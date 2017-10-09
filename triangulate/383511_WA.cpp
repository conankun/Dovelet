#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
struct A {
	double x,y;
};
A convex[1000];
double dp[100][100];
int n;
int main() {
	scanf("%d",&n);
	int d,i,j,k;
	for(i=1;i<=n;i++) scanf("%lf%lf",&convex[i].x,&convex[i].y);
	for(d=2;d<=n;d++) {
		for(i=1;i<=n-d;i++) {
			j=i+d;
			double a = abs(convex[i].x-convex[j].x);
			double b = abs(convex[i].y-convex[j].y);
			if(!(j==n&&i==1)) {
				dp[i][j] = sqrt(a*a+b*b);
			}
			double mn=99999999.00;
			for(k=i+1;k<j;k++) {
				if(k != i) {
					if(dp[i][k]+dp[k][j] < mn) {
						mn = dp[i][k]+dp[k][j];
					}
				}
			}
			dp[i][j]+=mn;
		}
	}
	double sum=dp[1][n];
	for(i=2;i<=n;i++) {
		double a = abs(convex[i].x-convex[i-1].x);
		double b = abs(convex[i].y-convex[i-1].y);
		sum+=sqrt(a*a+b*b);
	}
	printf("%.2lf",sum);
}