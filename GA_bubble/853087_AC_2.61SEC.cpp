#include<stdio.h>
long long N;
long long arr[1000000];
long long intree[5000000];
int main() {
	scanf("%lld",&N);
	long long i;
	for(i=1;i<=N;i++) scanf("%lld",&arr[i]);
	long long cnt=0;
	long long size=1;
	while(size<N) size*=2;
	for(i=N;i>=1;i--) {
		bool ok=true;
		long long ls=size+1,rs=size+arr[i]; 
		long long sum=0;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=false;
			if(ls%2==1) {
				sum+=intree[ls];
				ls++;
			} 
			if(rs%2==0) {
				sum+=intree[rs];
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		rs=size+arr[i];
		while(rs>0) {
			intree[rs]+=1;
			rs/=2;
		}
		cnt+=sum;
	}
	printf("%lld",cnt);
}