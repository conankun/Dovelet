#include<iostream>
#include<string>
#include<iostream>
using namespace std;
struct A {
	int price;
	char check[1000];
};
struct B {
	int limit,price;
};
B arr[10000]={0};
int n;
int main() {
	int sum=0;
	int i,j,k;
	for( i=0;;i++) {if(cin>>arr[i].limit>>arr[i].price){n++;} else break;}

	for( i=0;i<n;i++) {
		int vis[10000]={0};
		int lv=arr[i].limit-1;
		int ss=arr[i].price;
		vis[i]=1;
		for( k=lv;k>=1;k--) {
			int mx=0,in;
			for( j=0;j<n;j++) {
				if(vis[j] == 0 && arr[j].price > mx && arr[j].limit >= k) {
					mx = arr[j].price;
					in = j;
				}
			}
			ss+=mx;
			vis[in]=1;
		}
		if(ss > sum) sum = ss;
	}
	cout<<sum;
}