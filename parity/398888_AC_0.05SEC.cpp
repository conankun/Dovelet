#include<iostream>
using namespace std;
int r[1001];//행
int l[1001];//열
int n;
int map[1000][1000];
bool t1=true;
int r2,l2,r3,l3;
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
		}
	}
	for(i=1;i<=n;i++) {
		int cnt=0;
		for(j=1;j<=n;j++) {
			cnt+=map[i][j];
		}
		r[i] = cnt;
		if(cnt%2 == 1) {
			t1=false;
			r2++;
			r3=i;
		}
	}
	for(j=1;j<=n;j++) {
		int cnt=0;
		for(i=1;i<=n;i++) {
			cnt+=map[i][j];
		}
		l[j]=cnt;
		if(cnt%2 == 1) {
			t1=false;
			l2++;
			l3=j;
		}
	}
	if(t1) {
		cout<<"ok";
	} else {
		if(r2 == 1 && l2 == 1) {
			printf("change bit (%d,%d)",r3,l3);
		} else {
			printf("error");
		}
	}
}