#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int primes[1000000];
int insu[1000000];
int ind,index;
int main() {
	scanf("%d",&n);
	printf("%d ",n/3+(n%3!=0));
	int i,j;
	for(j=2;j<=n;j++) {
		bool t=true;
		for(i=2;i*i<=j;i++) {
			if(j%i==0) {
				t=false;
				break;
			}
		}
		if(t) primes[++ind]=j;
	}
	int m=n;
	while(m > 1) {
		for(i=1;i<=ind;i++) {
			if(m%primes[i]==0) {
				m/=primes[i];
				insu[++index]=primes[i];
				break;
			}
		}
	}
	sort(insu+1,insu+1+index);
	m=index;
	for(i=2;i<=index;i++) {
		if(insu[i] == 2 && insu[i-1] == 2 && i%2==0) {
			m--;
		}
	}
	printf("%d",m);
}