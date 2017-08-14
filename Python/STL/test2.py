# Enter your code here. Read input from STDIN. Print output to STDOUT# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
import collections
import itertools


def isvalid(move):
    global n, m, c
    if move < 1 or move > n:
        return 0
    return 1


def possible_moves(move, p):
    global A
    ans = []
    for i in range(1, p + 1):
        if isvalid(move + i):
            ans.append(move + i)
        if isvalid(move - i):
            ans.append(move - i)
    # print ans
    # raise ValueError
    return ans


def BFS(m, A):
    global ans
    queue = collections.deque()
    queue.append((m, 1))
    while queue:
        cur, level = queue.popleft()
        # print cur, level
        # if level == m:
        ans[cur] += 1
        if level < m:
            for moves in possible_moves(cur, A[level - 1]):
               # print moves
                queue.append((moves, level + 1))
            # ans[moves]+=1
        # if level == m:
            # break


a = int(raw_input())
# a = 1
for _ in range(a):

    n, m, c = tuple(map(int, raw_input().split(' ')[:3]))
    #n.m, c = k[0], k[1], k[2]
    A = map(int, raw_input().split(' '))
    ans = [0] * (n + 1)
    BFS(c, A)
    print ans[1:]
    # print possible_moves(3, 6)
# Enter your code here. Read input from STDIN. Print output to STDOUT# Enter your code here. Read input from STDIN. Print output to STDOUT
