#include<iostream>
using namespace std;
int map[1000][1000];
int n;
int our[101]={0};
int chk[101]={0};
int filled[101]={0};
int another[101]={0};
bool tr=false;
void DFS(int ind,int level,int code) {
	int i;
	bool t=true;
	for(i=1;i<=n;i++) {
		if(i == ind) continue;
		if(chk[i] == code && map[ind][i] == 1) {
			t=false;
			break;
		}
		if(chk[i] != code && filled[i] != code && map[ind][i] == 0) {
			t=false;
			break;
		}
	}
	if(!t || level <  2) {
		for(i=ind+1;i<=n;i++) {
			if(chk[i] == 0 && filled[i] == 0) {
				chk[i]=code;
				DFS(i,level+1,code);
				chk[i]=0;
			}
		}	
	} else {
		tr=true;
		int count=0;
		for(i=1;i<=n;i++) {
			if(chk[i] == code) {
				filled[i]=code;
				count++;
			}
		}
		if(n-count < 2) {
			for(i=1;i<=n;i++) {
				if(chk[i] == code) {
					filled[i]=0;
				}
			}
			tr=false;
		}
	}
}
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
		}
		another[i]=99999999;
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		if(filled[i]==0) {
			cnt++;
			chk[i]=cnt;
			DFS(i,1,cnt);
			chk[i]=0;
			if(!tr) cnt--;
		}
	}
	cout<<cnt<<endl;
	for(i=1;i<=cnt;i++) {
		for(j=1;j<=n;j++) {
			if(filled[j] == i) cout<<j<<" ";
		}
		cout<<endl;
	}
}