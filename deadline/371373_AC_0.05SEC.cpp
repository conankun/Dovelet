#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct A {
	int limit,price;
	bool operator<(const A &a) const {
		return price > a.price;
	}
};
A deadline[10001];
int n;
int main() {
	while(cin>>deadline[n].limit>>deadline[n].price) n++;
	sort(deadline,deadline+n);
	int i,j;
	vector<A> ve;
	ve.push_back(deadline[0]);
	for(i=1;i<n;i++) {
		vector<A> imsi;
		int ind=0;
		bool t=true;
		if(deadline[i].limit <= ve[0].limit) {
			t=false;
			imsi.push_back(deadline[i]);
		}
		for(j=0;j<ve.size();j++) {
			if(ve[j-1].limit <= deadline[i].limit && ve[j].limit >= deadline[i].limit && t) {
				t=false;
				imsi.push_back(deadline[i]);
			}
			imsi.push_back(ve[j]);
		}
		if(t) {
			imsi.push_back(deadline[i]);
		}
		t=true;
		for(j=0;j<imsi.size();j++) {
			if(imsi[j].limit < j+1) {
				t=false;
				break;
			}
		}
		if(t) {
			ve.resize(imsi.size());
			for(j=0;j<imsi.size();j++) ve[j] = imsi[j];
		}
	}
	int sum=0;
	for(i=0;i<ve.size();i++) {
		sum+=ve[i].price;
	}
	cout<<sum;
}