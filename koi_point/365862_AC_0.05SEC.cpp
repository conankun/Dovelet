#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int a,b;
	cin>>a>>b;
	int g=abs(a-b);
	while(!(g%2)) {
		g/=2;
	}
	//abs(a-b)의 최소 비율.
	int i;
	for(i=0;i<5;i++) {
		int c,d;
		cin>>c>>d;
		if(a == b) {
			if(c == d) cout<<"Y"<<endl;
		} else {
			if(c == d || (a-b)*(c-d) < 0) { //x<y인데 a>b인경우 같을때나 x!=y인데 a==b인경우 성립할 수 없다.
				cout<<"N"<<endl;
			} else if(abs(c-d)%g == 0) cout<<"Y"<<endl; //그 차이가 최소간격의 배수일경우.
			else cout<<"N"<<endl;
		}
	}
}