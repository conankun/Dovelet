#include<iostream>
#include<stdlib.h>
using namespace std;
struct A {
	int x,y;
};
struct B {
	int x,y;
};
//y-x입력;
int n,w;
A work[10000];
int police[10000];
int dp[1005][1005];
B back[2000][2000];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	cin>>n>>w;
	int i,j;
	work[1].x = 1;
	work[1].y = 1;
	work[2].x = n;
	work[2].y = n;
	for(i=3;i<=w+2;i++) {
		cin>>work[i].y>>work[i].x;
	}
	for(i=1;i<=w+10;i++) for(j=1;j<=w+10;j++) dp[i][j]=99999999;
	int mn=99999999;
	dp[1][2]=0;     
	B b;
	for(i=3;i<=w+2;i++) {
		for(j=1;j<i;j++) {
			if(dp[i][i-1] > dp[j][i-1]+abs(work[j].y-work[i].y)+abs(work[j].x-work[i].x)) {
				dp[i][i-1] = dp[j][i-1]+abs(work[j].y-work[i].y)+abs(work[j].x-work[i].x);
				back[i][i-1].x = i-1;
				back[i][i-1].y = j;
			}
			if(dp[j][i] > dp[j][i-1]+abs(work[i-1].y-work[i].y)+abs(work[i-1].x-work[i].x)) {
				dp[j][i] = dp[j][i-1]+abs(work[i-1].y-work[i].y)+abs(work[i-1].x-work[i].x);
				back[j][i].x = i-1;
				back[j][i].y = j;
			}
			if(i == w+2 ) {
				if(mn > dp[j][i]) {
					mn = dp[j][i];
					b.x = i;
					b.y = j;
				}
				if(mn > dp[i][i-1]) {
					mn = dp[i][i-1];
					b.x = i-1;
					b.y = i;
				}
			}
		}
		for(j=1;j<i;j++) {
			if(dp[i][j] > dp[i-1][j]+abs(work[i-1].y-work[i].y)+abs(work[i-1].x-work[i].x)) {
				dp[i][j] = dp[i-1][j]+abs(work[i-1].y-work[i].y)+abs(work[i-1].x-work[i].x);
				back[i][j].x = j;
				back[i][j].y = i-1;
			}
			if(dp[i-1][i] > dp[i-1][j]+abs(work[j].y-work[i].y)+abs(work[j].x-work[i].x)) {
				dp[i-1][i] = dp[i-1][j]+abs(work[j].y-work[i].y)+abs(work[j].x-work[i].x);
				back[i-1][i].x = j;
				back[i-1][i].y = i-1;
			}
			if(i == w+2) {
				if(mn > dp[i][j]) { 
					mn = dp[i][j];
					b.x = j;
					b.y = i;
				}
				if(mn > dp[i-1][i]) {
					mn = dp[i-1][i];
					b.x = i;
					b.y = i-1;
				}
			}
		}
	}
	cout<<mn<<endl;
	for(i=w+2;i>=3;i--) {
		if(b.x == i) {
			police[i] = 2;
		} else if(b.y == i) {
			police[i] = 1;
		}
		B c;
		c.x = back[b.y][b.x].x;
		c.y = back[b.y][b.x].y;
		b = c;
	}
	for(i=3;i<=w+2;i++) {
		cout<<police[i]<<endl;
	}
}
