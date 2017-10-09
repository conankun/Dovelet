#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int s=n;
	int d=0;
	int sum=n;
	int cnt=0;
	while(1) {
		if(s+d == cnt || (s+d)/3 < cnt) {
			break;
		}
		if(s%3 == 2) {
			cnt++;
			s+=1;
		}
		sum+=s/3;
		d = s%3;
		s/=3;
		s+=d;
		if((s+1)/3 == 0) break;
	}
	cout<<sum;
}