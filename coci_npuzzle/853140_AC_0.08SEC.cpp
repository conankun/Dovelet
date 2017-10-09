#include<iostream>
#include<stdlib.h>
using namespace std;
char a[100][100];
int main() {
	int i,j;
	for(i=1;i<=4;i++) {
		for(j=1;j<=4;j++) {
			cin>>a[i][j];
		}
	}
	int sum=0;
	for(i=1;i<=4;i++) {
		for(j=1;j<=4;j++) {
			if(a[i][j]!='.') {
				sum+=abs(i-((a[i][j]-'A')/4+1));//y
				int k=(a[i][j]-'A')/4;//b4 lines elements
				int aa=(a[i][j]-'A')-4*k;
				sum+=abs(j-aa%4-1);
			}
		}
	}
	printf("%d",sum);
}