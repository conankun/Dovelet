#include<iostream>
#include<algorithm>
using namespace std;
double arr[1000000];
double sum,sum2;
int n,m;
int main() {
	int i;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(i=m;i<n-m;i++) sum+=arr[i];
	for(i=0;i<m;i++) {
		arr[i] = arr[m];
	}
	for(i=n-1;i>=n-m;i--) {
		arr[i] = arr[n-1-m];
	}
	for(i=0;i<n;i++) sum2+=arr[i];
	printf("%.2lf\n%.2lf",sum/(n-m*2),sum2/n);
}