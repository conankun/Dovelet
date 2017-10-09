#include<iostream>
#include<cmath>
#include<algorithm>
#include<float.h>
using namespace std;
int n,i;
double sum;
int arr[6000000];
int main() {
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		arr[a]++;
		sum = sum+a/(double)n;
	}
	int s=0;
	int ind=0;
	for(i=1;i<=10000;i++) {
		s+=arr[i];
		if(s >= n/2 && n%2 == 0) {
			ind = i;
			break;
		} else if(s >= n/2+1 && n%2 == 1) {
			ind = i;
			break;
		}
	}
	double a = sum;
	double b = a-(int)a;
	if(fabs(b-0.5) <= 0.000000001) {
		cout<<ind<<" "<<(int)sum;
	} else {
		printf("%d %.0f",ind,sum);
	}
}