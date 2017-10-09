#include<iostream>
using namespace std;
int n;
int map[1000];
int chk[1000]; //0 = 존재 , 1 = 비존재.
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>map[i];
	bool t=true;
	while(t) {
		t=false;
		for(i=1;i<=n;i++) {
			bool tr=false;
			if(chk[i] == 1) continue;
			for(j=1;j<=n;j++) {
				if(map[j] == i && chk[j] == 0) {
					tr=true;
				}
			}
			if(!tr)  {
				chk[i]=1;
				t=true;
			}
		}
	}
	int cnt=0;
	for(i=1;i<=n;i++) if(chk[i] == 0) cnt++;
	cout<<cnt<<endl;
	for(i=1;i<=n;i++) if(chk[i] == 0) cout<<i<<endl;
}