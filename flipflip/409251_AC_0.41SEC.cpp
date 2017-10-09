#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
int square[10001];
int imsi[10001];
int imsi2[10001];
struct A {
	int s,e;
};
A gugans[1000];
int ind;
bool t=false;
int a,b;
void flipflip(int s,int e,int level) {
	int i,j;
	if(t) return;
	A gugans2[1000]={0};
	int index=0;
	for(i=1;i<=n;i++) {
		if(level==2)imsi[i]=square[i];
		if(level==1)imsi2[i]=imsi[i];
	}
	int cnt=0;
	for(i=0;i<e-s;i++) {
		if(level == 2) {
			imsi[i+s]=square[e-i];
			imsi[e-i]=square[i+s];
		} else {
			imsi2[i+s]=imsi[e-i];
			imsi2[e-i]=imsi[i+s];
		}
	}
	if(level == 1) {
		bool tr=true;
		for(i=2;i<=n;i++) if(imsi2[i]<imsi2[i-1]) {tr=false;break;}
		if(tr) {
			t=true;
			printf("%d %d\n%d %d",a,b,s,e);
		}
		return;
	}
	int ss=1;
	for(i=2;i<=n;i++) {
		if(abs(imsi[i]-imsi[i-1]) > 1) {
			gugans2[++index].s=ss;
			gugans2[index].e=i-1;
			ss=i;
			cnt++;
		} else if(i == n) {
			gugans2[++index].s=ss;
			gugans2[index].e=i;
			cnt++;
		}
	}
	for(i=1;i<=index;i++) {
		for(j=i;j<=index;j++) {
			if(t) break;
			a=s;
			b=e;
			flipflip(gugans2[i].s,gugans2[j].e,1);
			flipflip(gugans2[i].s,gugans2[j].e-1,1);
			flipflip(gugans2[i].s-1,gugans2[j].e,1);
			flipflip(gugans2[i].s-1,gugans2[j].e-1,1);
		}
	}
}
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&square[i]);
	int s=1;
	int cnt=0;
	for(i=2;i<=n;i++) {
		if(abs(square[i]-square[i-1]) > 1) {
			gugans[++ind].s=s;
			gugans[ind].e=i-1;
			s=i;
			cnt++;
		} else if(i == n) {
			gugans[++ind].s=s;
			gugans[ind].e=i;
			cnt++;
		}
	}
	if(cnt <= 1) {
		printf("1 1\n1 1");
		return 0;
	}
	if(cnt <= 3) {
		flipflip(1,1,2);
	}
	for(i=1;i<=ind;i++) {
		for(j=i;j<=ind;j++) {
			if(t) break;
			flipflip(gugans[i].s,gugans[j].e,2);
			flipflip(gugans[i].s,gugans[j].e-1,2);
			if(gugans[i].s > 1) {
				flipflip(gugans[i].s-1,gugans[j].e,2);
				flipflip(gugans[i].s-1,gugans[j].e-1,2);
			}
		}
	}
}