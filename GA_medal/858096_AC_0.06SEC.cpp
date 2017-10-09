#include<stdio.h>
#include<algorithm>
using namespace std;
int score[100];
int n=10;
int sunho;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int i;
	for(i=1;i<=n;i++) scanf("%d",&score[i]);
	scanf("%d",&sunho);
	sunho=score[sunho];
	sort(score+1,score+1+10,cmp);
	for(i=1;i<=n;i++) {
		if(sunho==score[i]) {
			if(i==1) printf("WINNER");
			else if(i>=2 && i<=3) printf("GOLD");
			else if(i>=4 && i<=6) printf("SILVER");
			else printf("BRONZE");
		}
	}
}