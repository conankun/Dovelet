#include<iostream>
using namespace std;
int n;
int main() {
	cin>>n;
	int i,j,k,z;
	int win=0;
	int ma=-1;
	for(i=1;i<=n;i++) {
		int card[10];
		for(j=1;j<=5;j++) cin>>card[j];
		int mx=0;
		for(j=1;j<=5;j++) {
			for(k=j+1;k<=5;k++) {
				for(z=k+1;z<=5;z++) {
					if((card[j]+card[k]+card[z])%10 > mx) mx = (card[j]+card[k]+card[z])%10;
				}
			}
		}
		if(ma < mx) {
			ma = mx;
			win = i;
		}
	}
	cout<<win;
}