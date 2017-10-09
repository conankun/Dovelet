#include<iostream>
#include<algorithm>
using namespace std;
struct A {
	int limit,price;
	bool operator<(const A &a) const {
		if(price/(double)limit == a.price/(double)a.limit) {
			return limit < a.limit;
		}
		return price/(double)limit > a.price/(double)a.limit;
	}
};
int n;
A arr[100];
int main() {
	while(cin>>arr[n].limit>>arr[n].price){
		n++;
	}
	sort(arr,arr+n);
	int i;
	int d=1;
	int sum=0;
	for(i=0;i<n;i++) {
		if(arr[i].limit >= d) {
			sum+=arr[i].price;
			d++;
		}
	}
	cout<<sum;
}