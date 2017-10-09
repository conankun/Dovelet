#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[111111];
int b[111111];
int abs(int bbb) {
    if(bbb<0) return -1*bbb;
    return bbb;
}
int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    sort(a+1,a+1+m);
    sort(b+1,b+1+m);
    int x = a[m/2];
    int y = b[m/2];
    int sum=0;
    for(i=1;i<=m;i++) {
        sum+=abs(x-a[i]);
        sum+=abs(y-b[i]);
    }
    cout<<sum;
}
