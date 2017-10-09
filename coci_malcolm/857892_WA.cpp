#include<stdio.h>
#include<string.h>
int length[1000000];
int lengthsum[311111][32];
int n,k;
int main() {
	scanf("%d%d\n",&n,&k);
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
	int sum=0;
	for(i=1;i<=n;i++) {
		int fr=lengthsum[i+k][length[i]]-lengthsum[i][length[i]];
		fr+=lengthsum[i-1][length[i]]-lengthsum[i-k-1][length[i]];
		sum+=fr;
	}
	printf("%d",sum/2);

}