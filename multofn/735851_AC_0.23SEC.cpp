#include<stdio.h>
int a[10],n,cnt;
void back(int lv) {
	if(lv==4) {
		if((a[1]+a[2]*10+a[3]*100+a[4]*1000)%n == 0) {
			cnt++;
		}
		return;
	}
	int i;
	for(i=1;i<=3;i++) {
		a[lv+1]=i;
		back(lv+1);
	}
}
int main() {
	scanf("%d",&n);
	back(0);
	printf("%d",cnt);
}