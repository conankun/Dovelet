#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bitset>
using namespace std;
int bin2[1000];
int bin3[1000];
int index;
int ind;
int main() {
	int n;
	int i;
	while(scanf("%d",&n) != -1) {
		bitset<32> binmake(n);
		ind=0;
		index=0;
		for(i=24;i<=31;i++) {
			bin3[++index]=binmake[i];
		}
		for(i=16;i<=23;i++) {
			bin3[++index]=binmake[i];
		}
		for(i=8;i<=15;i++) {
			bin3[++index]=binmake[i];
		}
		for(i=0;i<=7;i++) {
			bin3[++index]=binmake[i];	
		}
		bitset<32> bit2;
		for(i=32;i>=1;i--) bit2[i-1]=bin3[i];
		printf("%d converts to %d\n",n,bit2.to_ulong());
	}
}