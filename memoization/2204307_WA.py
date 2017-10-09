def pow(p,n):
    unit = p
    ans = 1
    while n > 0:
        if n%2 is 1:
            ans = ans * unit
        unit = unit * unit
        n = n / 2
    return ans

n=0
m = int(raw_input())
while m > 0:
    m = m - 1
    a1,p,q,k,n = map(int, raw_input().split())
    ans = a1*pow(p,n-1) + (1-pow(p,n-1)) * (q/(1-p));
    ans = ans % k
    print ans
