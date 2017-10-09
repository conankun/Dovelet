#include<iostream>
using namespace std;
int maxtree[1000000];
int mintree[1000000];
int size=1;
int n,q;
void maxtreepush(int idx,int data) {
	int rs=size+idx-1;
	while(rs > 0) {
		if(maxtree[rs] < data) maxtree[rs]=data;
		rs/=2;
	}
}
void mintreepush(int idx,int data) {
	int rs=size+idx-1;
	while(rs > 0) {
		if(mintree[rs] > data || mintree[rs] == 0) mintree[rs]=data;
		rs/=2;
	}
}
int findmaxtree(int a,int b) {
	int ld = size+a-1,rd = size+b-1;
	bool ok=true;
	int max=0;
	while(ld<=rd&&ok) {
		if(ld == rd) ok=false;
		if(ld%2 == 1) {
			if(max < maxtree[ld]) max = maxtree[ld];
			ld++;
		}
		if(rd % 2 == 0) {
			if(max < maxtree[rd]) max = maxtree[rd];
			ld--;
		}
		ld/=2;
		rd/=2;
	}
	return max;
}
int findmintree(int a,int b) {
	int ld = size+a-1,rd = size+b-1;
	bool ok=true;
	int min=99999999;
	while(ld<=rd&&ok) {
		if(ld == rd) ok=false;
		if(ld%2 == 1) {
			if(min > mintree[ld]) min = mintree[ld];
			ld++;
		}
		if(rd % 2 == 0) {
			if(min > mintree[rd]) min = mintree[rd];
			ld--;
		}
		ld/=2;
		rd/=2;
	}
	return min;
}
int main() {
	int i,j;
	scanf("%d %d",&n,&q);
	for(;size<n;size*=2);
	for(i=1;i<=n;i++) {
		int K;
		scanf("%d",&K);
		maxtreepush(i,K);
		mintreepush(i,K);
	}
	for(i=1;i<=q;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		int max = findmaxtree(a,b);
		int min = findmintree(a,b);
		printf("%d\n",max-min);
	}
}