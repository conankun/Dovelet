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
			if(j == 1) {
				x+=i-1;
				break;
			} else if(i == 1) {
				y+=j-1;
				break;
			}
			if(i < j) {
				y+=j/i;
				j-=i*(j/i);
			} else {
				x+=i/j;
				i-=j*(i/j);
			}
		}
		printf("Scenario #%d:\n",d);
		printf("%d %d\n\n",x,y);
	}
}