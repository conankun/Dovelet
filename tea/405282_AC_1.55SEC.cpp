#include<iostream>
#include<cmath>
using namespace std;
int n;
int arr[100000];
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) arr[i]=i;
	int cnt=0;
	int m=ceil(n/2.);
	for(i=1;i<=m;i++) {
		for(j=1;j<m;j++) {
			if(arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				cnt++;
			}
		}
	}
	for(i=m+1;i<=n;i++) {
		for(j=m+1;j<=n;j++) {
			if(arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				cnt++;
			}
		}
	}
	cout<<cnt;
}