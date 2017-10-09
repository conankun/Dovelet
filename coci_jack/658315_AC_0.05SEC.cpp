#include<stdio.h>
bool dp[300001];
int n,m;
int arr[100000];
int main() {
    scanf("%d %d",&n,&m);
    int i,j,k,l=0;
    for(i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(i=1;i<=n;i++) {
        for(j=i+1;j<=n;j++) {
            for(k=j+1;k<=n;k++) {
                if(m-l > m-(arr[i]+arr[j]+arr[k]) && m >= arr[i]+arr[j]+arr[k]) {
                    l=arr[i]+arr[j]+arr[k];
                }
            }
        }
    }
    printf("%d",l);
}