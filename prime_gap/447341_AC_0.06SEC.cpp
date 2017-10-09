#include<iostream>
using namespace std;
int primes[1300000];
int prime[100001];
int floodfill[1300000];
int ind;
int i,j;
int main() {
	for(i=1;i<=1299709;i++) primes[i] = 1;
	for(i=2;i*i<=1299709;i++) {
		if(primes[i]==0) continue;
		for(j=2*i;j<=1299709;j+=i) {
			primes[j] = 0;
		}
	}
	primes[1] = 0;
	for(i=1;i<=1299709;i++) if(primes[i]) prime[++ind] = i;
	for(i=1;i<=ind-1;i++) {
		int s = prime[i];
		int e = prime[i+1];
		for(j=s+1;j<e;j++) {
			floodfill[j] = e-s;
		}
	}
	int n;
	while(cin>>n) {
		if(n == 0) break;
		cout<<floodfill[n]<<endl;
	}
}