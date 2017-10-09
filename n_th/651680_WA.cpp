#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,x;
int a[100],b[100],c[100];
char chk[100000001];
int cnt;
void back(int level) {
    int i;
    if(level==m) {
        int sum=0;
        int lv=1;
        for(i=m;i>=1;i--) {
            sum+=c[i]*lv;
            lv*=10;
        }
        if(chk[sum]==0) {
            cnt++;
            chk[sum]=1;
            if(cnt==x) {
                for(i=1;i<=m;i++) {
                    printf("%d",c[i]);
                }
            }
        }
        return;
    }
    for(i=1;i<=n;i++) {
        if(b[i]==0) {
            b[i]=1;
            c[level+1]=a[i];
            back(level+1);
            b[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d%d",&m,&x);
    sort(a+1,a+1+n);
    back(0);
}

