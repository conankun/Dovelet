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
	plate[1]=s[1];
	plate[2]=s[2];
	plate[3]=s[3];
	for(i=4;i<=n;i++) {
		int ind[4]={99999999,99999999,99999999,99999999};
		int mx=0;
		int id=0;
		if(plate[1] == s[i] || plate[2] == s[i] || plate[3] == s[i]) continue;
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