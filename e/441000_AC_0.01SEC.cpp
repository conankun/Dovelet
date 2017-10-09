#include<stdio.h>
double dp[1000];
int main() {
	int i;
	printf("n e\n- -----------\n");
	printf("0 1\n");
	dp[0]=1;
	int fact=1;
	for(i=1;i<=9;i++) {
		fact*=i;
		dp[i] = dp[i-1]+1.00/fact;
		printf("%d %.10lf\n",i,dp[i]);
	}
}