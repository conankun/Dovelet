#include<stdio.h>
#include<string.h>
long long length[1000000];
long long lengthsum[1111111][32];
long long n,k;
int main() {
	scanf("%lld%lld\n",&n,&k);
	int i,j;
	for(i=1;i<=n;i++) {
		char s[100];
		scanf("%s",s);
		length[i]=strlen(s);
	}
	for(i=1;i<=n+k;i++) {
		for(j=2;j<=20;j++) {
			lengthsum[i][j]=lengthsum[i-1][j];
		}
		lengthsum[i][length[i]]+=1;
	}
	long long sum=0;
	for(i=1;i<=n;i++) {
		long long fr=lengthsum[i+k][length[i]]-lengthsum[i][length[i]];
		fr+=lengthsum[i-1][length[i]]-lengthsum[i-k-1][length[i]];
		sum+=fr;
	}
	printf("%lld",sum/2);

}