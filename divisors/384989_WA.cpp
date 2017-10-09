#include<iostream>
using namespace std;
bool isPrime(int n) {
	if(n == 1) return false;
	int i;
	for(i=2;i*i<=n;i++) {
		if(n%i == 0) return false;
	}
	return true;
}
int prime[1000];
int soinsu[1000];
int sosu[1000][1000];
int ind;
void bunhae(int n,int d) {
	while(n > 1) {
		int i;
		for(i=0;i<ind;i++) {
			if(n%prime[i] == 0) {
				sosu[d][prime[i]]++;
				n/=prime[i];
			}
		}
	}
}
int main() {
	int n,k;
	int i,j;
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
		int sum=1;
		for(i=1;i<=1000;i++) sum*=(soinsu[i]+1);
		cout<<sum<<endl;
	}
}