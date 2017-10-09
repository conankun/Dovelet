#include<iostream>
using namespace std;
bool isPrime(unsigned long long n) {
	if(n == 1) return false;
	unsigned long long i;
	for(i=2;i*i<=n;i++) {
		if(n%i == 0) return false;
	}
	return true;
}
unsigned long long prime[1000];
unsigned long long soinsu[1000];
unsigned long long sosu[1000][1000];
unsigned long long ind;
void bunhae(unsigned long long n,unsigned long long d) {
	while(n > 1) {
		unsigned long long i;
		for(i=0;i<ind;i++) {
			if(n%prime[i] == 0) {
				sosu[d][prime[i]]++;
				n/=prime[i];
			}
		}
	}
}
int main() {
	unsigned long long n,k;
	unsigned long long i,j;
	for(i=2;i<=1000;i++) if(isPrime(i)) prime[ind++]=i;
	for(i=2;i<=1000;i++) {
		for(j=2;j<=i;j++) {
			bunhae(j,i);
		}
	}
	while(scanf("%lld%lld",&n,&k) != -1) {
		for(i=1;i<=1000;i++) soinsu[i] = sosu[n][i];
		for(i=1;i<=1000;i++) soinsu[i] -= sosu[k][i];
		for(i=1;i<=1000;i++) soinsu[i] -= sosu[n-k][i];
		unsigned long long sum=1;
		for(i=1;i<=1000;i++) sum*=(soinsu[i]+1);
		cout<<sum<<endl;
	}
}