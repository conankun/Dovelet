#include<iostream>
#include<deque>
using namespace std;
deque<int> de;
int main() {
	int i;
	int a[5];
	int sum=0,g=1000;
	for(i=1;i<=4;i++) {
		cin>>a[i];
		sum+=g*a[i];
		g/=10;
	}
	int mn=sum;
	for(i=1;i<=4;i++) {
		int ab = sum%10;
		sum/=10;
		sum+=ab*1000;
		if(sum < mn) mn = sum;
	}
	int cnt=0;
	for(i=1111;i<=9999;i++) {
		int test = i;
		bool t=true;
		while(test > 0) {
			if(test%10 == 0) {
				t=false;
				break;
			}
			test/=10;
		}
		int mn2 = i;
		int s = i;
		int j;
		for(j=1;j<=4;j++) {
			int ab = s%10;
			s/=10;
			s+=ab*1000;
			if(s < mn2) mn2 = s;
		}
		if(t && mn2 == i) {
			cnt++;
			if(i == mn) {
				cout<<cnt;
				return 0;
			}
		}
	}
}