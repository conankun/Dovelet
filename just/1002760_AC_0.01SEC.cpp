#include <iostream>
using namespace std;
int main()
{
    int n,i,j;
    int x;
    while(scanf("%d",&n)!=EOF){
        int s=0;
        x=1;
        for(i=5;i<=n;i*=5) {
            s+=n/i;
        }
        for(i=1;i<=n;i++) {
            j=i;
            while(j%5==0) j/=5;
            while(j%2==0&&s>0) {j/=2;s--;}
            x*=j;
            x%=10;
        }
        printf("%5d -> %d\n",n,x);
    }
}