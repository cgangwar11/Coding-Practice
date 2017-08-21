import pickle
x, xt, y, yt = pickle.load(open('A1.pickle'))
print x.shape, xt.shape, y.shape, yt.shape

from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix
clf1 = RandomForestClassifier(n_estimators=5000)
clf1.fit(x, y)
pred = clf1.predict(xt)
print accuracy_score(yt, pred)
print confusion_matrix(yt, pred)
