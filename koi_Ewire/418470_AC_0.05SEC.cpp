#include<stdio.h>
#include<algorithm>
using namespace std;
struct A {int s,e,ind;bool operator<(const A &a) const {return s < a.s;}};struct B {int value,ind;};
int n;
A wire[1000000];
int chk[1000000];
int bt[1000000];
int dp[1000000];
B tree[4000000];
int print[1000000];
int main() {scanf("%d",&n);int i;for(i=1;i<=n;i++) {scanf("%d%d",&wire[i].s,&wire[i].e);wire[i].ind=i;}sort(wire+1,wire+1+n);int size=1;for(;size<=500000;size*=2);int ans=0;int index=-1;for(i=1;i<=n;i++) {int ls=size,rs=size+wire[i].e-1;bool ok=true;int back=0,mx=0;while(ls<=rs&&ok) {if(ls==rs) ok=false;if(ls%2==1) {if(mx < tree[ls].value) {back = tree[ls].ind;mx = tree[ls].value;}ls++;}if(rs%2==0) {if(mx < tree[rs].value) {back = tree[rs].ind;mx = tree[rs].value;}rs--;}ls/=2;rs/=2;}bt[i]=back;dp[i]=mx+1;if(dp[i] > ans) {ans = dp[i];index = i;}rs = size+wire[i].e;while(rs > 0) {if(tree[rs].value < dp[i]) {tree[rs].ind=i;tree[rs].value = dp[i];}rs/=2;}}int indexed=index;chk[index]=1;while(indexed > 0) {indexed=bt[indexed];chk[indexed]=1;}int count=0;for(i=1;i<=n;i++){if(chk[i]==0){count++;print[count]=wire[i].s;}}printf("%d\n",count);}