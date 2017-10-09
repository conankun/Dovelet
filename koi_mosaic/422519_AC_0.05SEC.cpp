#include<stdio.h>
#include<algorithm>
using namespace std;
int mn=2147483647;
int h,w;
int paper;
int n;
struct A {int y,x;bool operator<(const A &a) const {if(a.x == x) return y < a.y;return x < a.x;}};
A papers[10000];
int ans=2147483647;
void parametric(int low,int high) {if(low>high) return;int mid=(low+high)/2;int i,j;int count=paper;int counts=0;int highs=1;bool tr=false;for(i=1;i<=n;i++) {if(papers[i].x >= highs && papers[i].x <= highs+mid-1 && papers[i].y <= mid) {counts++;if(!tr) highs = papers[i].x;if(!tr) count--;tr=1;} else if(papers[i].y <= mid) {counts++;highs = papers[i].x;count--;tr=1;} else {tr=0;}}if(counts==n&&count >= 0) {if(ans > mid) ans = mid; parametric(low,mid-1);} else {parametric(mid+1,high);}}int main(){scanf("%d%d",&h,&w);scanf("%d",&paper);scanf("%d",&n);int i;for(i=1;i<=n;i++) scanf("%d%d",&papers[i].y,&papers[i].x);sort(papers+1,papers+1+n);parametric(1,1000000);printf("%d",ans);}
