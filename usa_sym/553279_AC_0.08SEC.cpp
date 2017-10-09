#include<stdio.h>
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	int g=1,sum=0;
	while(1) {
		if(n%2==0||m%2==0) {
			break;
		}
		sum+=g;
		n/=2;
		m/=2;
		g*=4;
	}
	printf("%d",sum);
}