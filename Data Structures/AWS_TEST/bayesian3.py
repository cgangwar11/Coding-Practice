import pickle
from collections import Counter

feature_all, test_set_all = None, None
yid, labels_type_1, labels_type_2 = None, None, None


def load_data(normal=False, lda=False):
  global feature_all, test_set_all, yid, labels_type_1, labels_type_2
  feat_set_1 = pickle.load(open('cont_feat_sum.pickle'))
  feat_set_2 = pickle.load(open('cat.pickle'))
  test_set_1 = pickle.load(open('cont_test_sum.pickle'))
  test_set_2 = pickle.load(open('test_cat.pickle'))
  yid = pickle.load(open('ids.pickle'))

  labels = pickle.load(open('labels.pickle'))
  labels_type_1 = labels
  labels_type_2 = [min(1, i) for i in labels]

  if normal:
    feat_set_1 = normalize(feat_set_1)
    test_set_1 = normalize(test_set_1)
  if normal:
    feat_set_2 = normalize(feat_set_2)
    test_set_2 = normalize(test_set_2)

  out1 = feat_set_1
  out2 = feat_set_2
  out_test1 = test_set_1
  out_test2 = test_set_2

  if lda:
    out1, out_test1 = apply_lda(feat_set_1, out_test1, 4)
    out2, out_test2 = apply_lda(feat_set_2, out_test2, 4)

  import numpy as np
  feature_all = np.hstack((out1, out2))
  test_set_all = np.hstack((out_test1, out_test2))


def normalize(x):
  from sklearn.preprocessing import normalize
  return normalize(x)


# In[5]:


import sklearn


def apply_lda(features, test, val):
  from sklearn.decomposition import PCA
  a = PCA(n_components=val)
  out = a.fit_transform(features)
  out2 = a.transform(test)
  print a.explained_variance_ratio_
  return out, out2


# print feature_all.shape, test_set_all.shape
load_data(False,False)


import pandas as pd
import xgboost as xgb
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import mean_absolute_error
from bayes_opt import BayesianOptimization
from tqdm import tqdm


def xgb_evaluate(min_child_weight,
                 colsample_bytree,
                 max_depth,
                 subsample,
                 gamma,
                 alpha):

  params['min_child_weight'] = int(min_child_weight)
  params['cosample_bytree'] = max(min(colsample_bytree, 1), 0)
  params['max_depth'] = int(max_depth)
  params['subsample'] = max(min(subsample, 1), 0)
  params['gamma'] = max(gamma, 0)
  params['alpha'] = max(alpha, 0)

  cv_result = xgb.cv(params, xgtrain, num_boost_round=num_rounds, nfold=2,
                     seed=random_state,
                     callbacks=[xgb.callback.early_stop(50)])
 # print cv_result

  return cv_result['test-auc-mean'].values[-1]


def prepare_data_for_xgb():
  global feature_all, test_set_all, yid, labels_type_1, labels_type_2
  train = feature_all
  # categorical_columns = train.select_dtypes(include=['object']).columns

  # for column in tqdm(categorical_columns):
  # le = LabelEncoder()
  # train[column] = le.fit_transform(train[column])

  # y = train['loss']

  # X = train.drop(['loss', 'id'], 1)
  xgtrain = xgb.DMatrix(feature_all, label=labels_type_2)

  return xgtrain


xgtrain = prepare_data_for_xgb()

num_rounds = 3000
random_state = 2016
num_iter = 25
init_points = 5
params = {
    'eta': 0.1,
    'silent': 1,
    'eval_metric': 'auc',
    'verbose_eval': True,
    'seed': random_state
    
}

xgbBO = BayesianOptimization(xgb_evaluate, {'min_child_weight': (15, 18),
                                            'colsample_bytree': (0.2, 0.32),
                                            'max_depth': (10, 13),
                                            'subsample': (0.7, 0.9),
                                            'gamma': (0, 1),
                                            'alpha': (8, 9),
                                            })

xgbBO.maximize(init_points=init_points, n_iter=1)
print xgbBO.res
# 3 | 00m35s |    0.66847 |    8.5023 |             0.2856 |    0.8671 |     11.9805 |            16.7821 |      0.8323 | 
# alpha |   colsample_bytree |     gamma |   max_depth |   min_child_weight |   subsample |
#    6 | 02m08s |    0.66962 |    8.0325 |             0.3200 |    1.0000 |     13.0000 |            18.0000 |      0.8704 | 
