#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int b[1000];//빈도수
char plate[4];
int main() {
	cin>>n;
	int i,j,k;
	s.resize(n+1);
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++) {
		b[s[i]]++;
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		int ind=0;
		int mn=999999999;
		bool t=false;
		for(j=1;j<=3;j++) {
			if(plate[j] == 0 || plate[j] == s[i]) {
				t=true;
				plate[j]=s[i];
				b[plate[j]]--;
				break;
			}
			if(plate[j] != 0 && b[plate[j]] < mn) {
				mn = b[plate[j]];
				ind=j;
			} else if(plate[j] != 0 && b[plate[j]] == mn) {
				int ss=0;
				int m1=0;
				int m2=0;
				for(k=i+1;k<=n;k++) {
					if(plate[ind] == s[k]) ss++;
					else if(s[k] == plate[j]) {
						ss=0;
						if(ss > m1) m1 = ss;
					}
				}
				ss=0;
				for(k=i+1;k<=n;k++) {
					if(plate[j] == s[k]) ss++;
					else if(s[k] == plate[ind]) {
						ss=0;
						if(ss > m2) m2 = ss;
					}
				}
				if(m1 < m2) {
					mn = b[plate[j]];
					ind=j;
				}
			}
		}
		if(!t) {
			plate[ind] = s[i];
			b[plate[ind]]--;
			cnt++;
		}
	}
	cout<<cnt;
}