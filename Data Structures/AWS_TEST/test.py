import pickle
import numpy as np
x, xt, y, yt = pickle.load(open('A1.pickle'))
print x.shape, xt.shape, y.shape, yt.shape

# from sklearn.ensemble import RandomForestClassifier
# from sklearn.metrics import accuracy_score, confusion_matrix
# clf1 = RandomForestClassifier(n_estimators=5000)
# clf1.fit(x, y)
# pred = clf1.predict(xt)
# print accuracy_score(yt, pred)
# print confusion_matrix(yt, pred)
labels = y
balanced = True


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
clf1 = RandomForestClassifier(n_estimators=3000, n_jobs=-1)
clf1.fit(x, y)
pred = clf1.predict(xt)
print accuracy_score(yt, pred)
print confusion_matrix(yt, pred)

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

# pickle.dump((rsearch.best_score_, rsearch.best_estimator_), open('Ridge.pickle', 'wb'))
