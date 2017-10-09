#include<iostream>
using namespace std;
int n,m,k;
int root[10000];
int edit[10000];
int main() {
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++) cin>>root[i];
	for(i=1;i<=k;i++) cin>>edit[i];
	bool t=true;
	int cnt=0;
	while(t) {
		t=false;
		int ind=-1;
		for(i=1;i<=k;i++) {
			if(edit[i]>root[i]) {
				ind=i;
				break;
			}
		}
		if(ind==-1) break;
		for(i=1;i<=k;i++) {
			if(i != ind && edit[i]<root[i]) {
				root[i]--;
				root[ind]++;
				cnt++;
				t=true;
				break;
			}
		}
	}
	cout<<cnt;
}