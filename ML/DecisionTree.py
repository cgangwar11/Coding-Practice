from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_iris
import pandas as pd
from collections import Counter
from statistics import mode

data = load_iris()

train,labels = data.data,data.target

clf = DecisionTreeClassifier()
clf.fit(train,labels)

class Decision():
    def __init__(self,value=None,feature=None,isleaf=None,left_node=None,right_node = None,classified=None):
        self.value = value
        self.feature = feature
        self.isleaf = isleaf
        self.left_node = left_node
        self.right_node = right_node
        self.classified = classified
       # print(self.left_node,self.right_node,self.isleaf)

    def __repr__(self):
        return f'{self.value} {self.feature}'

class DecisionTree():
    def __init__(self):
        pass
    def _gini(self,labels):

        p_list = [(float(i)/len(labels))**2 for i in list(dict(Counter(labels)).values())]
        return 1-sum(p_list)
    def _information_gain(self,data,value,labels):

        true_labclfels = labels[data<value]
        false_labels = labels[data>=value]
        p = float(len(true_labels))/len(labels)
        gain = self._gini(labels)-p*self._gini(true_labels)-(1-p)*self._gini(false_labels)
        return gain
    def fit(self,X,y):
        self.rows = X
        self.labels = y
        self.root = self._build_tree(X,y)
    def _find_best_split(self,data,y):

        best_feat,best_val = 0,0
        max_gain = 0
        for feat in range(data.shape[1]):
            values = list(set(data[:,feat]))
            for val in values:
                gain = self._information_gain(data[:,feat],val,y)

                if gain>max_gain:
                    best_feat,best_val = feat,val
                    max_gain = gain

        return best_feat,best_val,max_gain
    def _build_tree(self,data,y):

        feat,val,gain = self._find_best_split(data,y)

        if gain==0:
            print(y)
            return Decision(val,feat,1,classified=mode(list(y)))
        cond = data[:,feat]<val
        not_cond = data[:,feat]>=val
        true_data = data[cond]
        true_y = y[cond]
        false_data = data[not_cond]
        false_y = y[not_cond]

        true_node = self._build_tree(true_data,true_y)
        false_node = self._build_tree(false_data,false_y)

        ans = Decision(val,feat,0,true_node,false_node)

        return ans

    def _value(self,row,node):
        if node.isleaf:
            return node.classified
        if node.value >= row[node.feature]:
            return self._value(row,node.left_node)
        return self._value(row,node.right_node)


    def predict(self,data):
        return [self._value(i,self.root) for i in data]

tree = DecisionTree()

tree.fit(train,labels)

print(accuracy_score(tree.predict(train),labels))

