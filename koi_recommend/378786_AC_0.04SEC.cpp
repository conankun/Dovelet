#include<iostream>
#include<deque>
using namespace std;
int n,m;
int chu[1000];
int vis[1000];
deque<int> de;
int chk[1000];
int main() {
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++) {
		int a;
		cin>>a;
		chu[a]++;
		if(de.size() < n && !vis[a]) {
			de.push_back(a);
			vis[a]=1;
			chk[de.size()-1]=i;
		}
		else if(!vis[a]) {
			int mn=99999999;
			int ind=0;
			int min2=9999999;
			for(j=0;j<n;j++) {
				if(chu[de[j]] < mn || (chu[de[j]] == mn && min2 > chk[j])) {
					mn = chu[de[j]];
					ind = j;
					min2 = chk[j];
				}
			}
			vis[de[ind]]=0;
			chu[de[ind]]=0;
			de[ind] = a;
			chk[ind]=i;
			vis[a]=1;
		}
	}
	for(i=0;i<n;i++) if(de[i] != 0) cout<<de[i]<<" ";
}