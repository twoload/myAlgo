#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
import sys
n,m = map(int, input().split())
a = [0]*m
c = [False]*(n+1)

def go(index, start, n, m):
    if index == m:
        sys.stdout.write(' '.join(map(str,a))+'\n')
        return
    for i in range(start, n+1):
        if c[i]: 
            continue
        c[i] = True
        a[index] = i
        go(index+1, i+1, n, m)
        c[i] = False
        
go(0,1,n,m)