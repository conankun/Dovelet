#include<iostream>
using namespace std;
int main() {
	int T;
	cin>>T;
	int d;
	int i,j;
	for(d=1;d<=T;d++) {
		cin>>i>>j;
		int x=0,y=0;
		while(i!=j) {
			if(i < j) {
				y++;
				j = j-i;
			} else {
				x++;
				i = i-j;
			}
		}
		printf("Scenario #%d:\n",d);
		printf("%d %d\n",x,y);
	}
}