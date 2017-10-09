#include<iostream>
using namespace std;
int n;
int su[100000];
int prime[100000];
int ind,indp;
int two,five;
bool isPrime(int f) {
	int i;
	if(f == 1) return false;
	if(f == 2) return true;
	if(f == 3) return true;
	for(i=3;i*i<=n;i+=2) {
		if(f%i == 0) return false;
	}
	return true;
}
void soinsubunhae(int f) {
	int i;
	int m=f;
	while(m > 1) {
		for(i=0;i<indp;i++) {
			if(m%prime[i] == 0) {
				su[ind++]=prime[i];
				if(prime[i] == 2) two++;
				else if(prime[i] == 5) five++;
				m/=prime[i];
				break;
			}
		}
	}
}
int main() {
	int i;
	cin>>n;
	for(i=1;i<=n;i++) {
		if(isPrime(i)) {
			prime[indp++]=i;
		}
	}
	for(i=2;i<=n;i++) {
		soinsubunhae(i);
	}
	int l=min(two,five);
	int tcnt=0,fcnt=0;
	for(i=1;i<ind;i++) {
		if(tcnt == l) break;
		if(su[i] == 2) {
			tcnt++;
			su[i]=1;
		}
	}
	for(i=1;i<ind;i++) {
		if(fcnt == l) break;
		if(su[i] == 5) {
			fcnt++;
			su[i]=1;
		}
	}
	int sum=1;
	for(i=0;i<ind;i++) {
		sum*=su[i];
		sum%=10;
	}
	cout<<sum%10;
}