#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i;
double sum;
int arr[6000000];
int main() {
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		sum = sum+arr[i]/(double)n;
	}
	sort(arr,arr+n);
	double a = sum;
	double b = a-(int)a;
	if(fabs(b-0.5) <= 0.00000000001) {
		printf("%d %d",arr[n/2-(1-n%2)],(int)sum);
	} else {
		printf("%d %.0f",arr[n/2-(1-n%2)],sum/(double)n);
	}
}