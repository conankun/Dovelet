#include<stdio.h>
int ans=0;
int main() {
	int i;
	int people=0;
	for(i=1;i<=4;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		people-=a;
		people+=b;
		if(people > ans) ans = people;
	}
	printf("%d",ans);
}
