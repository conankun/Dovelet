#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int n;
int tobin[10000]={0};
int i_n=0;
void tomake(int n) {
	while(n != 0) {
		int a = ceil((double)n/-2);
		tobin[i_n++]=abs(abs(n)-abs(-2*a)); //나머지
		n = a;
	}
}
int main() {
	cin>>n;
	if(n == 0) cout<<0;
		else {
		tomake(n);
		for(int i=i_n-1;i>=0;i--) cout<<tobin[i];
	}
}