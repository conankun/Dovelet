#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int i,j;
	int arr[100]={0};
	int ind=1;
	for(i=1;i<=n;i++) {
		int cnt=0;
		if(ind == n+1) ind=1;
		for(j=ind;j<=n;j++) {
			if(arr[j] == 0) cnt++;
			if(cnt == i+1) {
				arr[j]=i;
				ind = j+1;
				break;
			}
			if(j==n) j=0;
		}
	}
	for(i=1;i<=n;i++) cout<<arr[i]<<" ";
}