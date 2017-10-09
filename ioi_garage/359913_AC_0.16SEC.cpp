#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
int n,m,sum;
int i,j;
int parkprice[1000];
int car[10000];
int parking_lot[1000];
int size=0;
queue<int> qu;
int main() {
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>parkprice[i];
	for(i=1;i<=m;i++) cin>>car[i];
	for(i=1;i<=2*m;i++) {
		int a;
		cin>>a;
		if(a < 0) {
			for(j=1;j<=n;j++) {
				if(parking_lot[j] == abs(a)) {
					parking_lot[j]=0;
					break;
				}
			}
			if(!qu.empty()) {
				for(j=1;j<=n;j++) {
					if(parking_lot[j] == 0) {
						parking_lot[j] = qu.front();
						sum+=parkprice[j]*car[qu.front()];
						qu.pop();
						break;
					}
				}
			}
		} else {
			bool t=false;
			for(j=1;j<=n;j++) {
				if(parking_lot[j] == 0) {
					t=true;
					parking_lot[j] = a;
					sum+=parkprice[j]*car[a];
					break;
				}
			}
			if(!t) qu.push(a);
		}
	}
	cout<<sum;
}