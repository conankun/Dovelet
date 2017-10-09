#include<iostream>
using namespace std;
int n,q;
int days[1000];
int main() {
	cin>>n>>q;
	int i,j;
	for(i=0;i<n;i++) {
		int m;
		cin>>m;
		for(j=0;j<m;j++) {
			int d;
			cin>>d;
			days[d]++;
		}
	}
	int day=0;
	for(i=1;i<=1000;i++) {
		if(days[i] >= q && days[i] > days[day]) day = i;
	}
	cout<<day;
}