te = int(input())
def returnlist(n):
    upper = [-1]*len(n)
    lower = [len(n)]*len(n)
    stack = []
    for i,j in enumerate(n):
        while stack and j<n[stack[-1]]:
            lower[stack[-1]] = i
            stack.pop()
        stack.append(i)
    stack = []
    for i,j in enumerate(reversed(n)):
        i=len(n)-1-i
        while stack and j<n[stack[-1]]:
            upper[stack[-1]] = i
            stack.pop()
        stack.append(i)

    return lower,upper
            
    


for _ in range(te):
    rows = int(input())
    n=[int(x) for x in input().split()]
    #print(n)
    lower,upper = returnlist(n)
    window = [0]*(len(n)+1)
    for i,j in enumerate(zip(lower,upper)):
        size = j[0]-j[1]-1
        window[size] = max(window[size],n[i])
    jj = min(n)
    for i in range(len(n)-1,-1,-1):
        window[i]=max(window[i],window[i+1])
    print(" ".join([str(i) for i in window[1:]]))
    
    
