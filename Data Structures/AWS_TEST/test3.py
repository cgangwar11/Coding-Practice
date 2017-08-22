
from __future__ import division

import numpy as np
import xgboost as xgb
import pickle
import numpy as np
x, xt, y, yt, test = pickle.load(open('A1.pickle', 'rb'))
yid = pickle.load(open('ids.pickle', 'rb'))
print x.shape, xt.shape, y.shape, yt.shape, test.shape

labels = y
balanced = True


def sub(out, clf):
    global yid
    pred_full = zip(yid, out)
    out1 = sorted(pred_full, key=lambda x: -1 * x[1][1])
    out2 = sorted(pred_full, key=lambda x: -1 * x[1][2])
    out3 = sorted(pred_full, key=lambda x: -1 * x[1][3])
    from collections import OrderedDict
    ans = OrderedDict()
    output = {0: 'Supp', 2: 'Credit', 1: 'Elite'}
    count = 450
    pp = 0
    for i, j in out1:

        if i not in ans.keys() and pp < count:
            ans[i] = output[0]
    #         print "d"
            pp += 1
    count = 350
    pp = 0
    for i, j in out2:
        #     pp=0
        if i not in ans.keys() and pp < count:
            ans[i] = output[1]
    #         print "dd"
            pp += 1
    count = 200
    pp = 0
    for i, j in out3:
        #     pp=0
        if i not in ans.keys() and pp < count:
            ans[i] = output[2]
    #         print "ddd"
            pp += 1
    import csv

    with open(clf, 'wb') as out:
        csv_out = csv.writer(out)

        for row in ans.items():
            csv_out.writerow(row)


def count(A):
    from collections import Counter
    print Counter(A)


if balanced:
    good1 = [ind for ind, j in enumerate(labels) if j == 1]
    good2 = [ind for ind, j in enumerate(labels) if j == 2]
    good3 = [ind for ind, j in enumerate(labels) if j == 3]
    bad = [ind for ind, j in enumerate(labels) if j == 0]
    indices = np.array(good1 + good2 + good3 + bad[:12000])
    np.random.shuffle(indices)
    y = y[indices]
    x = x[indices]
count(y)

from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix
# clf1 = RandomForestClassifier(n_estimators=30, n_jobs=-1)
# clf1.fit(x, y)
# pred = clf1.predict(xt)
# print accuracy_score(yt, pred)
# print confusion_matrix(yt, pred)
# # out = clf1.predict_proba(test)
# from sklearn.grid_search import GridSearchCV

# rfc = RandomForestClassifier(n_jobs=-1, max_features='sqrt', oob_score=True)

# # Use a grid over parameters of interest
# param_grid = {
#     "n_estimators": [500],
#     "max_depth": [5, 10, 15, 20, 25, 30],
#     "min_samples_leaf": [2, 4, 6, 8, 10]}  # ], 2, 4, 6, 8, 10]}

# CV_rfc = GridSearchCV(estimator=rfc, param_grid=param_grid, cv=3)
# CV_rfc.fit(x, y)
# pred = CV_rfc.best_estimator_.predict(xt)
# print CV_rfc.best_params_
# print accuracy_score(yt, pred)
# print confusion_matrix(yt, pred)
# pred=CV_rfc.best_estimator_.predict(xt)
# sub(out, 'ppp.csv')
# pred_full = zip(yid,out)
# # # Randomized Search for Algorithm Tuning
# import numpy as np
# from scipy.stats import uniform as sp_rand
# from sklearn import datasets
# from sklearn.linear_model import Ridge
# from sklearn.model_selection import RandomizedSearchCV
# # load the diabetes datasets

# # prepare a uniform distribution to sample for the alpha parameter
# param_grid = {'alpha': sp_rand()}
# # create and fit a ridge regression model, testing random alpha values
# model = Ridge()
# rsearch = RandomizedSearchCV(estimator=model, param_distributions=param_grid, n_iter=5)
# rsearch.fit(x, y)
# print(rsearch)
# # summarize the results of the random parameter search
# print(rsearch.best_score_)
# print(rsearch.best_estimator_.alpha)

# pickle.dump((rsearch.best_score_, rsearch.best_estimator_), open('Ridge.pickle', 'wb'))from sklearn.ensemble import RandomForestClassifier


xg_train = xgb.DMatrix(x, label=y)
xg_test = xgb.DMatrix(xt, label=yt)
# setup parameters for xgboost
param = {}
# use softmax multi-class classification
param['objective'] = 'multi:softmax'
# scale weight of positive examples
param['eta'] = 0.1
param['max_depth'] = 6
param['silent'] = 1
param['nthread'] = 4
param['num_class'] = 4

watchlist = [(xg_train, 'train'), (xg_test, 'test')]
num_round = 5
bst = xgb.train(param, xg_train, num_round, watchlist)
# get prediction
pred = bst.predict(xg_test)
error_rate = np.sum(pred != yt) / yt.shape[0]
print('Test error using softmax = {}'.format(error_rate))

# do the same thing again, but output probabilities
param['objective'] = 'multi:softprob'
bst = xgb.train(param, xg_train, num_round, watchlist)
# Note: this convention has been changed since xgboost-unity
# get prediction, this is in 1D array, need reshape to (ndata, nclass)
pred_prob = bst.predict(xg_test).reshape(yt.shape[0], 4)
pred_label = np.argmax(pred_prob, axis=1)
error_rate = np.sum(pred != yt) / yt.shape[0]
print('Test error using softprob = {}'.format(error_rate))
