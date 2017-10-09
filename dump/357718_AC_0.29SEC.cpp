#include<iostream>
#include<bitset>
using namespace std;
int i,cnt;
int main() {
	int n;
	cin>>n;
	bitset<32> bit = bitset<32>(n);
	for(i=31;i>=0;i--) {
		cout<<bit[i];
		cnt++;
		if(cnt % 8 == 0) cout<<" ";
	}
}