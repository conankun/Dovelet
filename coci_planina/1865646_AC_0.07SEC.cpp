#include<iostream>
using namespace std;
int main() {
	int s=2;
	int e;
	cin>>e;
	for(int i=1;i<=e;i++) {
		s = 2*s-1;
	}
	cout<<s*s;
}