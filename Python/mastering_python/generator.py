"""
Generator pause the function until the next call
1.Basic E.g of Generator function based and class based

"""

"""1.Count"""

print("$1" * 10)


def count(*args, **kwargs):
    n = kwargs['start']
    while True:
        if n > kwargs['end']:
            return
        yield n
        n += kwargs['step']


class Count(object):
    def __init__(self, start=0, step=1, end=10):
        self.n = start
        self.step = step
        self.end = end

    def __iter__(self):
        return self

    def __next__(self):
        n = self.n
        if n > self.end:
            raise StopIteration()
        self.n += self.step
        return n

for i in Count():
    print(i)
for i in count(start=0, step=1, end=10):
    print(i)    




print ("$2"*10)

