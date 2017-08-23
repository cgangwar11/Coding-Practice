import pickle
from collections import OrderedDict
out = pickle.load(open('probabilty.pickle'))
yid = pickle.load(open('ids.pickle'))
best_sub = pickle.load(open('best_sub.pickle'))
make_dict = {i: j for i, j in best_sub}


def count(threshold):
    global out
    coun1 = 0
    for i in out:
        if i < threshold:
            coun1 += 1
    print coun1, 10000 - coun1


ids_bad = sorted(zip(out, yid), key=lambda x: -1 * x[0])[:1000]
ids_good = sorted(zip(out, yid), key=lambda x: x[0])[:400]
predicted = [i for i, j in best_sub]
list1 = [i for j, i in ids_bad]
list2 = [i for j, i in ids_good]
list3 = list(predicted)
common_good = list(set(list2).intersection(list3))
common_bad = list(set(list1).intersection(list3))
predicted = list(set(predicted) - set(common_bad))
remaining = list(set(predicted) - set(common_good))
remaining_include = list(set(list2) - set(common_good))
final_ans = OrderedDict()
for i in common_good:
    final_ans[i] = make_dict[i]
for i in remaining[:100]:
    final_ans[i] = make_dict[i]
for i in remaining_include:
    final_ans[i] = 'Supp'
for i in remaining[100:]:
    final_ans[i] = make_dict[i]

print len(final_ans.keys())

print len(common_bad), len(common_good)
import csv
with open('Tensorflaw_IITGuwahati_28.csv', 'wb') as out:
    csv_out = csv.writer(out)
    cot = 0

#     for row in zip(aa,result)
    for row in final_ans.items():
        if cot < 1000:
            csv_out.writerow(row)
        cot += 1
