#include<iostream>
using namespace std;
int root[1000000];
int back[1000000];
int n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&root[i]);
	for(i=1;i<=n;i++) {
		back[root[i]]=i;
	}
	bool t=true;
	for(i=1;i<=n;i++) {
		if(root[i] != back[i]) {
			t=false;
			break;
		}
	}
	if(t) {
		cout<<"ambiguous";
	} else {
		cout<<"not ambiguous";
	}
}