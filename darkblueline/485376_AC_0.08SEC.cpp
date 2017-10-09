#include<stdio.h>
int h,m,s;
int sec;
int main() {
	scanf("%d::%d::%d",&h,&m,&s);
	sec = 3600*h + 60*m + s;
	int ans=1000,ind=1;
	if(360-(sec%360!=0?sec%360:360) < ans) ans = 360-(sec%360!=0?sec%360:360);
	if(240-(sec%240!=0?sec%240:240) < ans) {
		ans = 240-(sec%240!=0?sec%240:240);
		ind=2;
	}
	printf("%d",ind);
}