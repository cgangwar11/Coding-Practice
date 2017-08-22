
# coding: utf-8

# In[1]:

import pickle
from collections import Counter
feat_set_1 = pickle.load(open('cont_feat_max.pickle'))
feat_set_2 = pickle.load(open('cat.pickle'))
test_set_1 = pickle.load(open('cont_test_max.pickle'))
test_set_2 = pickle.load(open('test_cat.pickle'))
yid = pickle.load(open('ids.pickle'))
normal = False
lda = False
# In[2]:

labels = pickle.load(open('labels.pickle'))


# In[3]:

labels_type_1 = labels
labels_type_2 = [min(1, i) for i in labels]


# In[4]:

def normalize(x):
    from sklearn.preprocessing import normalize
    return normalize(x)


if normal:
    feat_set_1 = normalize(feat_set_1)
    test_set_1 = normalize(test_set_1)
if normal:
    feat_set_2 = normalize(feat_set_2)
    test_set_2 = normalize(test_set_2)


# In[5]:

import sklearn


def apply_lda(features, test, val):
    from sklearn.decomposition import PCA
    a = PCA(n_components=val)
    out = a.fit_transform(features)
    out2 = a.transform(test)
    print a.explained_variance_ratio_
    return out, out2


out1 = feat_set_1
out2 = feat_set_2
out_test1 = test_set_1
out_test2 = test_set_2

if lda:
    out1, out_test1 = apply_lda(feat_set_1, out_test1, 4)
    out2, out_test2 = apply_lda(feat_set_2, out_test2, 4)


# In[6]:

import numpy as np
feature_all = np.hstack((out1, out2))
test_set_all = np.hstack((out_test1, out_test2))

# In[38]:

print feature_all.shape, test_set_all.shape

# In[31]:

from sklearn.model_selection import train_test_split


def split(feature_all):
    x, xt = feature_all[:-2000], feature_all[-2000:]
    y1, y1t = labels_type_1[:-2000], labels_type_1[-2000:]
    y2, y2t = labels_type_2[:-2000], labels_type_2[-2000:]
    return (x, xt, y1, y1t, y2, y2t)


x, xt, y1, y1t, y2, y2t = split(feature_all)


# In[43]:


# from sklearn.tree import DecisionTreeClassifier
# from sklearn.neural_network import multilayer_perceptron
# from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier, BaggingClassifier, ExtraTreesClassifier
# from sklearn.metrics import roc_auc_score, auc, confusion_matrix


# def fit_model(clf):
#     global x, y2, xt, y2t

#     clf = RandomForestClassifier(n_estimators=1000, n_jobs=-1, verbose=1, class_weight="balanced")
#     clf.fit(x, y2)
#     pred = clf.predict(xt)

#     print auc(y2t, pred)
#     print roc_auc_score(y2t, pred)
#     print confusion_matrix(y2t, pred)


# fit_model()
# models=[AdaBoostClassifier(n_estimators=500),BaggingClassifier(n_estimators=500,n_jobs=-1),ExtraTreesClassifier(n_estimators=500,n_jobs=-1)]
# for model in models:
#     fit_model(model)


# # In[35]:

# Counter(y2t)


# In[22]:

from sklearn.preprocessing import OneHotEncoder, label_binarize, LabelBinarizer


def binarizer(labels):
    A = LabelBinarizer()
    return A.fit_transform(labels)


# binarizer(y2t)
import xgboost as xgb
# label = np.random.randint(2, size=5) # binary target
dtrain = xgb.DMatrix(x, label=binarizer(y2))
dtest = xgb.DMatrix(xt, label=binarizer(y2t))
dleadr = xgb.DMatrix(test_set_all)
param = {'max_depth': 2, 'eta': 1, 'silent': 1, 'objective': 'binary:logistic'}
param['nthread'] = 4
param['eval_metric'] = 'auc'
plst = param.items()
evallist = [(dtest, 'eval'), (dtrain, 'train')]
num_round = 10
bst = xgb.train(plst, dtrain, num_round, evallist, early_stopping_rounds=10)
ypred = bst.predict(dleadr, ntree_limit=bst.best_ntree_limit)
print ypred[:5]


# yb.shape
# train(..., evals=evals, early_stopping_rounds=10)
