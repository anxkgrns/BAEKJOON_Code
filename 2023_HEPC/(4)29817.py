import sys

MOD = 10**9 + 7

def D(p,c,D_n,X):
    result = 0
    for i in range(1,p): # 1~ p-1
        result = (result +(-1)*((c**(p-i)))*(D_n[i+X-1]))
    return result

p,c,k = map(int, sys.stdin.readline().split())

money = [int(x) for x in sys.stdin.readline().split()]

D_n = [0 for _ in range(k)]
for i in range(p-1):
    D_n[i]=money[i+1]-money[i] 
for i in range(k-p+1):
    D_n[i+p-1]=D(p,c,D_n,i)
print(D_n)
answer = abs(D_n[k-1]) % MOD
print(answer)

