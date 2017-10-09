#include<stdio.h>
int N;
int s[1000000];
int Q;
int tree[1000000];
int main() {
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++) scanf("%d",&s[i]);
	int size=1;
	for(;size<N;size*=2);
	for(i=1;i<=N;i++) {
		int rs=size+i;
		while(rs > 0) {
			tree[rs]+=s[i];
			rs/=2;
		}
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		int ls=size+a,rs=size+b;
		bool ok=true;
		int sum=0;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=false;
			if(ls%2==1) {
				sum+=tree[ls];
				ls++;
			}
			if(rs%2==0) {
				sum+=tree[rs];
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		printf("%d\n",sum);
	}
}