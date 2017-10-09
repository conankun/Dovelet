#include<iostream>
#include<string>
using namespace std;
int y,m,d,cnt;
int i;
int days[20]={31,28,31,30,31,30,31,31,30,31,30,31};
string daystring[10]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
void output() {
	if(y%4 == 0 && m > 2) {
		if(y%100 == 0) {
			if(y%400 == 0) {
				cnt+=1;
			}
		} else {
			cnt+=1;
		}
	}
	for(i=0;i<m-1;i++) {
		cnt+=days[i];
	}
	cnt+=d;
	cnt--;
	cout<<daystring[cnt%7];
}
int main() {
	cin>>y>>m>>d;
	if(y < 1900) {
		for(i=y+1;i<=1900;i++) {
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
		for(i=1900;i<=y-1;i++) {
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

	output();
}