#include<stdio.h>
int main() {
	int i;
	int as=0,de=0;
	int b=0;
	for(i=1;i<=8;i++) {
		int a;
		scanf("%d",&a);
		if(a > b) as++;
		else de++;
		b=a;
	}
	if(as>=1 && de==0) {
		printf("ascending");
	} else if(de>=1 && as==0) {
		printf("decending");
	} else {
		printf("mixed");
	}
}