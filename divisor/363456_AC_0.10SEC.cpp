#include<iostream>
using namespace std;
int n;
int divisor[10000000];
int ind;
void yaksu() {
	int i;
	for(i=1;i*i<=n;i++) {
		if(n%i == 0) divisor[ind++]=i;
	}
}
int main() {
	int i;
	cin>>n;
	yaksu();
	int cnt=ind;
	for(i=0;i<ind;i++) {
		if(n/divisor[i] > divisor[i]) cnt++;
	}
	cout<<cnt;
}