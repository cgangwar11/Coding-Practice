import pickle
out = pickle.load(open('probabilty.pickle'))
yid = pickle.load(open('ids.pickle'))
best_sub = pickle.load(open('best_sub.pickle'))


def count(threshold):
    global out
    coun1 = 0
    for i in out:
        if i < threshold:
            coun1 += 1
    print coun1, 10000 - coun1


count(0.4)

ids = sorted(zip(out, yid), key=lambda x: -1*x[0])[:1000]
predicted = [i for i,j in best_sub]
list1 = [i for j,i in ids]
list2 = list(predicted)
print len(list(set(list1).intersection(list2)))
print predicted[:5]
print ids[:5]
