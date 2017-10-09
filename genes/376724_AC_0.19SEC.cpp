#include<iostream>
#include<deque>
using namespace std;
int dna[100000];
int chk[100000];
int n,r,q;
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) dna[i] = i;
	cin>>r;
	for(i=0;i<r;i++) {
		int a,b;
		cin>>a>>b;
		//a<->b reverse;
		deque<int> imsi;
		for(j=a;j<=b;j++) imsi.push_back(dna[j]);
		for(j=a;j<=b;j++) {
			dna[j] = imsi.back();
			imsi.pop_back();
		}
	}
	for(i=1;i<=n;i++) {
		chk[dna[i]]=i;
	}
	cin>>q;
	for(i=0;i<q;i++) {
		int te;
		cin>>te;
		cout<<chk[te]<<endl;
	}
}