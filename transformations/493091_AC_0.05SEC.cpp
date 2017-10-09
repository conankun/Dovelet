#include<stdio.h>
#include<iostream>
using namespace std;
int n;
struct A {
	char arr[100][100];
}before,after;
A rotate(A a) {
	A ret={0,};
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			ret.arr[j][n-i+1]=a.arr[i][j];
		}
	}
	return ret;
}
A flip(A a) {
	A ret={0};
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			ret.arr[i][n-j+1]=a.arr[i][j];
		}
	}
	return ret;
}
bool isEqual(A a,A b) {
	int i,j;
	bool ok=true;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(a.arr[i][j]!=b.arr[i][j]) {
				ok=false;
				break;
			}
		}
		if(!ok) break;
	}
	return ok;
}
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>before.arr[i][j];
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>after.arr[i][j];
		}
	}
	A nine=rotate(before);
	if(isEqual(nine,after)) {
		printf("1");
		return 0;
	}
	A hunde=rotate(nine);
	if(isEqual(hunde,after)) {
		printf("2");
		return 0;
	}
	A twohun=rotate(hunde);
	if(isEqual(hunde,after)) {
		printf("3");
		return 0;
	}
	A fli = flip(before);
	if(isEqual(fli,after)) {
		printf("4");
		return 0;
	}
	A flinine=rotate(fli);
	A flihunde=rotate(flinine);
	A flitwohun=rotate(flihunde);
	if(isEqual(flinine,after) || isEqual(flihunde,after) || isEqual(flitwohun,after)) {
		printf("5");
		return 0;
	}
	if(isEqual(before,after)) {
		printf("6");
		return 0;
	}
	printf("7");
	return 0;
}