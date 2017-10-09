#include<stdio.h>
#include<algorithm>
using namespace std;
int push1[20001];
int push2[20001];
int n,m,bin[20001];
int ans=0;
void parametric(int low,int high) {
  if(low>high) return;
  int i;
  int mid=(low+high)/2;
  for(i=1;i<=mid;i++) push1[i]=bin[i];
  for(i=mid+1;i<=mid+mid;i++) push2[i-mid]=bin[i];
  sort(push1+1,push1+1+mid);
  sort(push2+1,push2+1+mid);
  int t=1;
  for(i=mid;i>=1;i--) {
    if(push1[i]>=push2[i]) {
      t=0;
      break;
    }
  }
  if(t) {
    if(ans < mid) ans = mid;
    parametric(mid+1,high);
  } else {
    parametric(mid+1,high);
    if(ans < mid) parametric(low,mid-1);
  }
}
int main() {
  int i;
  scanf("%d%d",&m,&n);
  for(i=1;i<=n;i++) scanf("%d",&bin[i]);
  parametric(1,n/2);
  printf("%d",ans);
}