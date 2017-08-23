
# coding: utf-8

# In[1]:

import pickle
from collections import Counter

feature_all, test_set_all = None, None
yid, labels_type_1, labels_type_2 = None, None, None


def load_data(normal=False, lda=False):
  global feature_all, test_set_all, yid, labels_type_1, labels_type_2
  feat_set_1 = pickle.load(open('cont_feat_max.pickle'))
  feat_set_2 = pickle.load(open('cat.pickle'))
  test_set_1 = pickle.load(open('cont_test_max.pickle'))
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


#print feature_all.shape, test_set_all.shape


#from __future__ import print_function
#from __future__ import division


import pandas as pd
import numpy as np
from sklearn.cross_validation import cross_val_score
from xgboost import XGBClassifier
from bayes_opt import BayesianOptimization


# def load_data(path_train = DATA_TRAIN_PATH, path_test = DATA_TEST_PATH):
#     train = pd.read_csv(path_train)
#     train_labels = [int(v[-1])-1 for v in train.target.values]
#     train_ids = train.id.values
#     train = train.drop('id', axis=1)
#     train = train.drop('target', axis=1)

#     test = pd.read_csv(path_test)
#     test_ids = test.id.values
#     test = test.drop('id', axis=1)

#     return np.array(train, dtype=float), \
#            np.array(train_labels), \
#            np.array(test, dtype=float),\
#            np.array(train_ids), \
#            np.array(test_ids)


def xgboostcv(max_depth,
              learning_rate,
              n_estimators,
              gamma,
              min_child_weight,
              max_delta_step,
              subsample,
              colsample_bytree,
              silent=True,
              nthread=-1,
              seed=1234):
  return cross_val_score(XGBClassifier(max_depth=int(max_depth),
                                       learning_rate=learning_rate,
                                       n_estimators=int(n_estimators),
                                       silent=silent,
                                       nthread=nthread,
                                       gamma=gamma,
                                       min_child_weight=min_child_weight,
                                       max_delta_step=max_delta_step,
                                       subsample=subsample,
                                       colsample_bytree=colsample_bytree,
                                       seed=seed,
                                       objective="multi:softprob"),
                         train,
                         labels,
                         "log_loss",
                         cv=4).mean()

#print "labels_type",len(labels_type_1)
load_data()
  # Load data set and target values
train, labels, test, _, _ = feature_all, labels_type_1, test_set_all, None, None


xgboostBO = BayesianOptimization(xgboostcv,
                                 {'max_depth': (5, 10),
                                  'learning_rate': (0.01, 0.3),
                                  'n_estimators': (50, 1000),
                                  'gamma': (1., 0.01),
                                  'min_child_weight': (2, 10),
                                  'max_delta_step': (0, 0.1),
                                  'subsample': (0.7, 0.8),
                                  'colsample_bytree': (0.5, 0.99)
                                  })

xgboostBO.maximize()
print('-' * 53)

print('Final Results')
print('XGBOOST: %f' % xgboostBO.res['max']['max_val'])


# # In[31]:

# from sklearn.model_selection import train_test_split


# def split(feature_all):
#     x, xt = feature_all[:-2000], feature_all[-2000:]
#     y1, y1t = labels_type_1[:-2000], labels_type_1[-2000:]
#     y2, y2t = labels_type_2[:-2000], labels_type_2[-2000:]
#     return (x, xt, y1, y1t, y2, y2t)


# x, xt, y1, y1t, y2, y2t = split(feature_all)


# # In[43]:


# # from sklearn.tree import DecisionTreeClassifier
# # from sklearn.neural_network import multilayer_perceptron
# # from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier, BaggingClassifier, ExtraTreesClassifier
# # from sklearn.metrics import roc_auc_score, auc, confusion_matrix


# # def fit_model(clf):
# #     global x, y2, xt, y2t

# #     clf = RandomForestClassifier(n_estimators=1000, n_jobs=-1, verbose=1, class_weight="balanced")
# #     clf.fit(x, y2)
# #     pred = clf.predict(xt)

# #     print auc(y2t, pred)
# #     print roc_auc_score(y2t, pred)
# #     print confusion_matrix(y2t, pred)


# # fit_model()
# # models=[AdaBoostClassifier(n_estimators=500),BaggingClassifier(n_estimators=500,n_jobs=-1),ExtraTreesClassifier(n_estimators=500,n_jobs=-1)]
# # for model in models:
# #     fit_model(model)


# # # In[35]:

# # Counter(y2t)


# # In[22]:

# from sklearn.preprocessing import OneHotEncoder, label_binarize, LabelBinarizer


# def binarizer(labels):
#     A = LabelBinarizer()
#     return A.fit_transform(labels)


# # binarizer(y2t)
# import xgboost as xgb
# # label = np.random.randint(2, size=5) # binary target
# dtrain = xgb.DMatrix(x, label=binarizer(y2))
# dtest = xgb.DMatrix(xt, label=binarizer(y2t))
# dleadr = xgb.DMatrix(test_set_all)
# param = {'max_depth': 2, 'eta': 1, 'silent': 1, 'objective': 'binary:logistic'}
# param['nthread'] = 4
# param['eval_metric'] = 'auc'
# plst = param.items()
# evallist = [(dtest, 'eval'), (dtrain, 'train')]
# num_round = 30000
# bst = xgb.train(plst, dtrain, num_round, evallist, early_stopping_rounds=10)
# ypred = bst.predict(dleadr, ntree_limit=bst.best_ntree_limit)
# pickle.dump(ypred,open('probability.pickle','wb'))


# print ypred[:5]


# # yb.shape
# # train(..., evals=evals, early_stopping_rounds=10)
