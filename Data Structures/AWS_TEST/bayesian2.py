
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
load_data(False,False)


from sklearn.datasets import make_classification
from sklearn.cross_validation import cross_val_score
from sklearn.ensemble import RandomForestClassifier as RFC
from sklearn.svm import SVC

from bayes_opt import BayesianOptimization

# Load data set and target values
data, target = feature_all, labels_type_2


def svccv(C, gamma):
  val = cross_val_score(
      SVC(C=C, gamma=gamma, random_state=2),
      data, target, 'roc_auc', cv=3
  ).mean()

  return val


def rfccv(n_estimators, min_samples_split, max_features):
  val = cross_val_score(
      RFC(n_estimators=int(n_estimators),
          min_samples_split=int(min_samples_split),
          max_features=min(max_features, 0.999),
          random_state=2,n_jobs=-1
          ),
      data, target, 'roc_auc', cv=3
  ).mean()
  print val
  return val


gp_params = {"alpha": 1e-5}

#svcBO = BayesianOptimization(svccv,
#                             {'C': (0.001, 100), 'gamma': (0.0001, 0.1)})
#svcBO.explore({'C': [0.001, 0.01, 0.1], 'gamma': [0.001, 0.01, 0.1]})

#rfcBO = BayesianOptimization(
 #   rfccv,
 #   {'n_estimators': (10, 1000),
 #    'min_samples_split': (2, 25),
 #    'max_features': (0.1, 0.999)}
#)
rfcBO = BayesianOptimization(
    rfccv,
    {'n_estimators': (776,800),
     'min_samples_split': (20, 30),
     'max_features': (0.1, 0.3)}
)

#svcBO.maximize(n_iter=10, **gp_params)
print('-' * 53)
rfcBO.maximize(n_iter=10, **gp_params)

print('-' * 53)
print('Final Results')
#print('SVC: %f' % svcBO.res['max']['max_val'])
print('RFC: %f' % rfcBO.res['max']['max_val'])

