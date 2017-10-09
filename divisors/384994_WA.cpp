#include<iostream>
using namespace std;
bool isPrime(long long n) {
	if(n == 1) return false;
	long long i;
	for(i=2;i*i<=n;i++) {
		if(n%i == 0) return false;
	}
	return true;
}
long long prime[1000];
long long soinsu[1000];
long long sosu[1000][1000];
long long ind;
void bunhae(long long n,long long d) {
	while(n > 1) {
		long long i;
		for(i=0;i<ind;i++) {
			if(n%prime[i] == 0) {
				sosu[d][prime[i]]++;
				n/=prime[i];
			}
		}
	}
}
int main() {
	long long n,k;
	long long i,j;
	for(i=2;i<=1000;i++) if(isPrime(i)) prime[ind++]=i;
	for(i=2;i<=1000;i++) {
		for(j=2;j<=i;j++) {
			bunhae(j,i);
		}
	}
	while(scanf("%d%d",&n,&k) != -1) {
		for(i=1;i<=1000;i++) soinsu[i] = sosu[n][i];
		for(i=1;i<=1000;i++) soinsu[i] -= sosu[k][i];
		for(i=1;i<=1000;i++) soinsu[i] -= sosu[n-k][i];
		long long sum=1;
		for(i=1;i<=1000;i++) sum*=(soinsu[i]+1);
		cout<<sum<<endl;
	}
}