import sys
import random
import itertools
import collections
import heapq
A = range(1, 10)

# def imp_queue(A):
# A.app
P = "AHUAHShSBHABSBS"
#


def combinatrics(A):
    for i in itertools.combinations(A, 3):
        print i
    for i in itertools.permutations(A, 3):
        print i
    for i in itertools.Product(A, A):
        print i


def strings(P):
    for i in itertools.chain(P, P):
        print i


def stack_and_queue():
    from collections import deque
    A = deque()
    A.append(1)
    A.append((1, 5))
    A.append((4, 7))

    print A.pop()
    print A.popleft()


stack_and_queue()
# strings(P)
