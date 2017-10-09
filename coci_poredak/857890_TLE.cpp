#include<iostream>
#include<string>
#include<map>
using namespace std;
int N;
string str[10000];//correct order
string str2[10000];
map<string,int> mp;
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
		for(j=i+1;j<=N;j++) {
			map<string,int>::iterator it=mp.find(str2[i]);
			map<string,int>::iterator it2=mp.find(str2[j]);
			if(it->second < it2->second) count++;
		}
	}
	cout<<count<<"/"<<(N*(N-1))/2;
	
}