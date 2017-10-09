#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n;
int i,j;
int arr[100000];
int main() {
	cin>>n;
	for(i=1;i<=n;i++) cin>>arr[i]>>arr[i];
	sort(arr+1,arr+1+n);
	int ind=ceil(n/2.00);
	int r=arr[ind];
	cout<<r;
}