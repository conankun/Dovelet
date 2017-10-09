#include<iostream>
#include<vector>
using namespace std;
vector<int> prime;
int s[10001];
bool isPrime(int n) {
	if(n == 1) return 0;
	int i;
	for(i=2;i*i<=n;i++) {
		if(n%i == 0) return 0;
	}
	return 1;
}
void bun(int n) {
	while(n > 1) {
		int i;
		for(i=0;i<prime.size();i++) {
			if(n%prime[i] == 0) {
				n/=prime[i];
				s[prime[i]]++;
			}
		}
	}
}
int main() {
	int i;
	for(i=1;i<=10000;i++) {
		if(isPrime(i)) {
			prime.push_back(i);
		}
	}
	for(i=1;i<=10;i++) {
		int su;
		cin>>su;
		bun(su);
	}
	int sum=1;
	for(i=1;i<=10000;i++) {
		sum*=s[i]+1;
	}
	cout<<sum;
}