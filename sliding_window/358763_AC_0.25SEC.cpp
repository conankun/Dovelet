#include<iostream>
#include<memory.h>
using namespace std;
int ptr[500000];
int ptr2[500000];
int data[200001];
int maxs[200001];
int mins[200001];
int n,k,i;
int size=1;
void maxtreepush(int e) {
	int rs = size+e;
	while(rs > 0) {
		if(ptr[rs] < data[e]) {
			ptr[rs] = data[e];
		}
		rs/=2;
	}
}
void mintreepush(int e) {
	int rs = size+e;
	while(rs > 0) {
		if(ptr2[rs] > data[e]) {
			ptr2[rs] = data[e];
		}
		rs/=2;
	}
}
int maxtree(int s,int e) {
	int ld=size+s,rd=size+e;
	bool ok=true;
	int mx=-2147483647;
	while(ld<=rd && ok) {
		if(ld == rd) ok=false;
		if(ld%2 == 1) {
			if(ptr[ld] > mx) mx = ptr[ld];
			ld++;
		}
		if(rd%2 == 0) {
			if(ptr[rd] > mx) mx = ptr[rd];
			rd--;
		}
		ld/=2;
		rd/=2;
	}
	return mx;
}
int mintree(int s,int e) {
	int ld=size+s,rd=size+e;
	bool ok=true;
	int mn=2147483647;
	while(ld<=rd && ok) {
		if(ld == rd) ok=false;
		if(ld%2 == 1) {
			if(ptr2[ld] < mn) mn = ptr2[ld];
			ld++;
		}
		if(rd%2 == 0) {
			if(ptr2[rd] < mn) mn = ptr2[rd];
			rd--;
		}
		ld/=2;
		rd/=2;
	}
	return mn;
}
int main() {
	cin>>n>>k;
	for(i=0;i<n;i++) cin>>data[i];
	for(;size<n;size*=2);
	memset(ptr,-21000000,sizeof(int)*400000);
	memset(ptr2,21000000,sizeof(int)*400000);
	for(i=0;i<n;i++) {
		maxtreepush(i);
		mintreepush(i);
	}
	int c=0;
	for(i=0;i<=n-k;i++) {
		maxs[c] = maxtree(i,i+k-1);
		mins[c++] = mintree(i,i+k-1);
	}
	for(i=0;i<c;i++) {
		cout<<mins[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<c;i++) {
		cout<<maxs[i]<<" ";
	}
}