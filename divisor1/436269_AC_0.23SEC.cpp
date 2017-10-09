#include<stdio.h>
long long A,B;
long long sum,count;
int main() {
	scanf("%lld%lld",&A,&B);
	long long i;
	for(i=1;i*i<=B;i++) {
		if(i*i >= A) {
		 sum+=(i%1000000003)*(i%1000000003);
		 count++;
		 sum%=1000000003;
		}
	}
	printf("%lld %lld",count,sum);
}