#include<stdio.h>
long long n,l;
long long tree[100000];
long long modulo[100000];
long long sum=0;
long long ans=2147483647;
long long index=0;
int main() {
	scanf("%lld%lld",&n,&l);
	long long i;
	for(i=1;i<=n;i++) {
		scanf("%lld",&tree[i]);
		modulo[tree[i]%l]++;
		sum+=tree[i]%l;
	}
	long long pivot=0;
	for(i=0;i<l;i++) {
		if(ans > sum-(modulo[pivot]*(l-1))+(n-modulo[pivot])) {
			ans = sum-(modulo[pivot]*(l-1))+(n-modulo[pivot]);
			index=i;
		}
		sum=sum-(modulo[pivot]*(l-1))+(n-modulo[pivot]);
		if(pivot==0) pivot=l-1;
		else pivot--;
	}
	printf("%lld",index);
}