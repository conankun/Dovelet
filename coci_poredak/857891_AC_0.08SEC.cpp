#include<iostream>
#include<string>
#include<map>
using namespace std;
int N;
string str[10000];//correct order
string str2[10000];
map<string,int> mp;
int value[10000];
int main() {
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) {
		cin>>str[i];
		mp[str[i]]=i;
	}
	for(i=1;i<=N;i++) {
		cin>>str2[i];
	}
	int count=0;
	for(i=1;i<=N;i++) {
		map<string,int>::iterator it=mp.find(str2[i]);
		value[i]=it->second;
	}
	for(i=1;i<=N;i++) {
		for(j=i+1;j<=N;j++) {
			if(value[i]<value[j]) count++;
		}
	}
	cout<<count<<"/"<<(N*(N-1))/2;
	
}