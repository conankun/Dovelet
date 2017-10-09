def pow(p,n,k):
    unit = p
    ans = 1
    while n > 0:
        if n%2 is 1:
            ans = ans * unit
        unit = unit * unit
        n = n / 2
    return ans%k

n=0
m = int(raw_input())
while m > 0:
    m = m - 1
    a1,p,q,k,n = map(int, raw_input().split())
    ans = 0
    if p is not 1:
        ans = 100*k + a1*pow(p,n-1) + q*((1-pow(p%k,n-1))/(1-p))
        ans = ans % k
    else:
        ans = a1-q + q*n
        ans = ans % k
    print ans
