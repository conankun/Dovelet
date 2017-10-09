#include<iostream>
using namespace std;
int n;
int y,x;
int map[100][100];
int main() {
	cin>>n;
	y = 1;
	x = n/2+1;
	int i=1,j;
	map[y][x]=1;
	if(y == 1) y = n;
	else y--;
	if(x == n && i%n != 0) x=1;
	else if(i%n != 0) x++;
	for(i=2;i<=n*n;i++) {
		map[y][x]=i;
		if(y == 1 && i%n != 0) y = n;
		else if(i%n != 0) y--;
		if(x == n && i%n != 0) x=1;
		else if(i%n != 0) x++;
		if(i%n == 0) y++;
		if(y == n+1) y = 1;
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("  %2d",map[i][j]);
		}
		cout<<endl;
	}
}