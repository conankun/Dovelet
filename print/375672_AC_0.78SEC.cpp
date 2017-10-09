#include<iostream>
#include<deque>
using namespace std;
struct A {
	int ind,value;
};
int vis[1000];
int n,m;
deque<A> de;
int main() {
	cin>>n>>m;
	int i,j;
	de.resize(n);
	for(i=0;i<n;i++) {
		cin>>de[i].value;
		de[i].ind = i+1;
	}
	int cnt=n;
	while(cnt) {
		A a = de.front();
		bool t=true;
		for(j=0;j<de.size();j++) {
			if(a.value < de[j].value) {
				t=false;
				break;
			}
		}
		if(t) {
			cnt--;
			vis[a.ind]=n-cnt;
			de.pop_front();
		} else {
			de.pop_front();
			de.push_back(a);
		}
	}
	cout<<vis[m+1];
}