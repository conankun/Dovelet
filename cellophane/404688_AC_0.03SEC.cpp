#include<iostream>
#include<map>
using namespace std;
map<char,int> mp;
int n;
int filled[21][21];
int main() {
	mp['W']=0;
	mp['B']=1;
	mp['Y']=2;
	mp['G']=3;
	mp['R']=4;
	mp['M']=5;
	mp['O']=6;
	mp['K']=7;
	cin>>n;
	int k,i,j;
	for(k=1;k<=n;k++) {
		int x,y,x1,y1;
		char cc;
		cin>>cc;
		cin>>x>>y;
		cin>>x1>>y1;
		for(i=y1;i<y;i++) {
			for(j=x;j<x1;j++) {
				int a = mp[cc];
				filled[i][j]=filled[i][j]|mp[cc];
			}
		}
	}
	char find;
	cin>>find;
	int cnt=0;
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(filled[i][j] == mp[find]) cnt++;
		}
	}
	printf("%d",cnt);
}