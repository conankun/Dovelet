#include<iostream>
using namespace std;
int arr[10000];
int main() {
	int n;
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++) {
		int m;
		cin>>m;
		for(j=1;j<=m;j++) cin>>arr[j];
		bool t=true;
		int cnt=0;
		while(t) {
			t=false;
			for(j=1;j<=m-1;j++) {
				if(arr[j] > arr[j+1]) {
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
					cnt++;
					t=true;
				}
			}
		}
		cout<<"Scenario #"<<i<<endl;
		cout<<cnt<<endl;
		if(i != n) cout<<endl;
	}
}