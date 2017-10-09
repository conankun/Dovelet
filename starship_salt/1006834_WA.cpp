#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <math.h>
using namespace std;
double a[1111],b[1111];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++) scanf("%lf%lf",&a[i],&b[i]);
    double kk;
    scanf("%lf",&kk);
    for(i=1;i<=n;i++) {
        for(j=i+1;j<=n;j++) {
            for(k=j+1;k<=n;k++) {
                //a[i]/100.*b[i] = the amount of salt
                //
                if(fabs(((a[i]/100*b[i] + a[j]/100*b[j] + a[k]/100*b[k])/(a[i]+a[j]+a[k]))-kk/100) <= 0.00000000001) {
                    printf("%d %d %d",i,j,k);return 0;
                }
            }
        }
    }
}