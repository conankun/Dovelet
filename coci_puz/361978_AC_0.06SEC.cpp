#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int a,b,v;
int main() {
	int total=0;
	cin>>a>>b>>v;
	int t=v-a;
	total+=ceil(t/(double)(a-b));
	total++;
	cout<<total;
}