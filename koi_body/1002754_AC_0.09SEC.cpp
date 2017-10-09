

#include <iostream>
using namespace std;
int a[10000],b[10000];
int c[10000];
int n;
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(i==j) continue;
            if(a[i] > a[j] && b[i] > b[j]) c[j]++;
        }
    }
    for(i=1;i<=n;i++) printf("%d ",c[i]+1);
}
