#include<iostream>
using namespace std;
int sum=0;
int n;
int d[10000];
void dance(int s,int e) {
	if(e-s == 1) {
		sum+=(d[s]*d[e]);
	} else if(e-s < 1) return;
	else {
		dance(s,(s+e)/2);
		dance((s+e)/2+1,e);
	}
}
int main() {
	cin>>n;
	int i;
	for(i=1;i<=n;i++) d[i]=i;
	dance(1,n);
	cout<<sum;
}