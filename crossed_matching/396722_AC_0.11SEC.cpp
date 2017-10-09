#include<iostream>
using namespace std;
int a[10000],b[10000],n,m,i,j,k,l,ans,d[200][200];
int main() {cin>>n>>m;for(i=1;i<=n;i++) cin>>a[i];for(i=1;i<=m;i++) cin>>b[i];for(i=1;i<=n;i++) {for(j=1;j<=m;j++) {d[i][j] = max(max(d[i-1][j],d[i][j-1]),d[i-1][j-1]);for(l=1;l<i;l++) {	for(k=1;k<j;k++) {int g = a[l]==b[j]&&a[i]==b[k]&&a[l] != a[i];if(d[l-1][k-1]+g*2 > d[i][j]) {d[i][j] = d[l-1][k-1]+g*2;}}}if(d[i][j] > ans) {ans = d[i][j];}}}cout<<ans;}