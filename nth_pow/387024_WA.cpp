#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int i,j;
	int g=10;
	for(i=1;i<=10;i++) { 
		for(j=1;j<=100;j++) { 
			int t=pow((double)j,(double)i); 
			if(t/g == 0 && t/(g/10) > 0) { 
				cout<<j<<"^"<<i<<endl; 
			} else if(t/g > 0) break; 
		} 
		g*=10; 
	}
	for(i=11;i<=21;i++) cout<<9<<"^"<<i<<endl;
}