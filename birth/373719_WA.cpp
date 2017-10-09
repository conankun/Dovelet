#include<iostream>
#include<string>
using namespace std;
int y,m,d,cnt;
int i;
int days[20]={31,28,31,30,31,30,31,31,30,31,30,31};
string daystring[10]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
int main() {
	cin>>y>>m>>d;
	if(y < 1900) {
		for(i=y;i<=1900;i++) {
			cnt+=365;
			if(i%4 == 0) {
				if(i%100 == 0) {
					if(i%400 == 0) {
						cnt+=1;
					}
				} else {
					cnt+=1;
				}
			}
		}
	} else if(y > 1900) {
		for(i=1900;i<=y;i++) {
			cnt+=365;
			if(i%4 == 0) {
				if(i%100 == 0) {
					if(i%400 == 0) {
						cnt+=1;
					}
				} else {
					cnt+=1;
				}
			}
		}
	}
	if(y%4 == 0) {
		if(y%100 == 0) {
			if(y%400 == 0) {
				cnt+=1;
			}
		} else {
			cnt+=1;
		}
	}
	for(i=1;i<m;i++) {
		cnt+=days[i];
	}
	cnt+=d-1;
	cnt--;
	cout<<daystring[cnt%7];
}