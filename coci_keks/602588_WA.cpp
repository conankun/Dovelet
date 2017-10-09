#include<stdio.h>
int k,n;
int ar[1111111],tree[2222222];
int main() {
	scanf("%d%d",&n,&k);
	scanf("\n");
	int i,j;
	int size=1;
	for(;size<n;size*=2);
	for(i=1;i<=n;i++) {char c;scanf("%c",&c);ar[i]=c-'0';tree[size+i]=ar[i];int rs=size+i;while(rs>0) {if(tree[rs]<ar[i]) tree[rs]=ar[i];rs/=2;}};
	int c=k;
	for(i=1;i<=n;i++) {
		int ls=size+i+1,rs=size+i+c,mx=0;
		bool ok=true;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=false;
			if(ls%2==1) {
				if(tree[ls] > mx) mx = tree[ls];
				ls--;
			}
			if(rs%2==0) {
				if(tree[rs]>mx) mx=tree[rs];
				rs++;
			}
			ls/=2;
			rs/=2;
		}
		if(mx > ar[i]) {ar[i]=-1;c--;}
	}
	for(i=1;i<=n;i++) if(ar[i]!=-1) printf("%d",ar[i]);
}