#include<iostream>
#include<string>
using namespace std;
int n,cnt;
string s;
int b[1000];//빈도수
char plate[4];
int main() {
	cin>>n;
	int i,j,k;
	s.resize(n+1);
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++) {
		int ind[4]={99999999,99999999,99999999,99999999};
		int mx=0;
		int id=0;
		if(plate[1] == s[i] || plate[2] == s[i] || plate[3] == s[i]) continue;
		bool t=false;
		for(j=1;j<=3;j++) {
			if(plate[j] == 0) {
				t=true;
				plate[j]=s[i];
				break;
			}
		}
		if(t) continue;
		for(j=1;j<=3;j++) {
			for(k=i+1;k<=n;k++) {
				if(s[k] == plate[j]) {
					ind[j]=k;
					break;
				}
			}
			if(mx < ind[j]) {
				mx = ind[j];
				id = j;
			}
		}
		plate[id]=s[i];
		cnt++;	
	}
	cout<<cnt;
}