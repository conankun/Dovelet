#include <iostream>
#include<algorithm>
using namespace std;
int n;
bool cmp(int a,int b) {
    if(a>b) return 1;
    return 0;
}
int flip1(int m) {
    int cnt=0,g=1;
    int a[10];
    while(m>0) {
        g*=10;
        cnt++;
        a[cnt]=m%10;
        m/=10;
    }
    g/=10;
    sort(a+1,a+cnt+1,cmp);
    int i,sum=0;
    for(i=1;i<=cnt;i++) {
        sum+=g*a[i];
        g/=10;
    }
    return sum;
}
int flip2(int m) {
    int cnt=0,g=1;
    int a[10];
    while(m>0) {
        g*=10;
        cnt++;
        a[cnt]=m%10;
        m/=10;
    }
    g/=10;
    sort(a+1,a+cnt+1);
    int i,sum=0;
    for(i=1;i<=cnt;i++) {
        sum+=g*a[i];
        g/=10;
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    int cnt=0;
    while(n!=6174) {
        n=flip1(n)-flip2(n);
        cnt++;
    }
    printf("%d",cnt);
}
