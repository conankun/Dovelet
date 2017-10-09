#include<stdio.h>
int n;
int months[100]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct A {
	int start,end;
};
int days(int month,int day) {
	int i;
	int sum=0;
	for(i=1;i<month;i++) sum+=months[i];
	return sum+day;
}
A flowers[100011];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		int s,e,ss,ee;
		scanf("%d%d%d%d",&s,&e,&ss,&ee);
		flowers[i].start = days(s,e);
		flowers[i].end = days(ss,ee)-1;
	}
	int tear=0;
	for(i=1;i<=n;i++) {
		if(flowers[i].start <= days(3,1) && tear < flowers[i].end) {
			tear=flowers[i].end;
		}
	}
	if(tear == 0) {
		printf("0");
		return 0;
	}
	int cnt=1;
	for(i=1;i<=365;i++) {
		bool t=false;
		int mx=0;
		for(j=1;j<=n;j++) {
			if(flowers[j].start <= tear+1 && flowers[j].end > mx) {
				mx=flowers[j].end;
				t=true;
			}
		}
		if(!t || tear >= mx) {
			printf("0");
			return 0;
		} else {
			tear = mx;
			cnt++;
		}
		if(tear >= days(11,30)) break;
	}
	printf("%d",cnt);
}
