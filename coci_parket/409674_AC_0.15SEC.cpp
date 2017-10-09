#include<iostream>
using namespace std;
int r,b;
int main() {
	cin>>r>>b;
	int i;
	for(i=r+b;i>=1;i--) {
		if(i < (r+b)/i) break;
		if((r+b)%i!=0) continue;
		int a = i*2+(((r+b)/i)-2)*2;
		if(a==r&&r+b-a == b) {
			printf("%d %d",i,(r+b)/i);
			break;
		}
	}
}