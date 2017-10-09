#include<iostream>
using namespace std;
#define n 10
int map[101][101];
int main() {
	int i,j,k;
	int mx=-999999999;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
		}
	}
	for(i=1;i<=n;i++) {
		for(j=n+1;j<=n+n;j++) {
			map[i][j] = map[i][j-n];
		}
	}
	for(i=1;i<=n;i++) {
		for(j=n+n+1;j<=n+n+n;j++) {
			map[i][j] = map[i][j-n];
		}
	}
	///
	for(i=n+1;i<=n+n;i++) {
		for(j=1;j<=n;j++) {
			map[i][j] = map[i-n][j];
		}
	}
	for(i=n+1;i<=n+n;i++) {
		for(j=n+1;j<=n+n;j++) {
			map[i][j] = map[i-n][j-n];
		}
	}
	for(i=n+1;i<=n+n;i++) {
		for(j=n+n+1;j<=n+n+n;j++) {
			map[i][j] = map[i-n][j-n];
		}
	}
	///
	for(i=n+1+n;i<=n+n+n;i++) {
		for(j=1;j<=n;j++) {
			map[i][j] = map[i-n][j];
		}
	}
	for(i=n+1+n;i<=n+n+n;i++) {
		for(j=n+1;j<=n+n;j++) {
			map[i][j] = map[i-n][j-n];
		}
	}
	for(i=n+1+n;i<=n+n+n;i++) {
		for(j=n+n+1;j<=n+n+n;j++) {
			map[i][j] = map[i-n][j-n];
		}
	}
	///
	for(i=n+1;i<=n+n;i++) {
		for(j=n+1;j<=n+n;j++) {
			int sum1=0,sum2=0,sum3=0,sum4=0;
			int s1=0,s2=0,s3=0,s4=0;
			for(k=i;k<=i+4;k++) {
				sum1+=map[k][j];
			}
			for(k=i;k<=i-4;k--) {
				s1+=map[k][j];
			}
			for(k=j;k<=j+4;k++) {
				sum2+=map[i][k];
			}
			for(k=j;k<=j-4;k--) {
				s2+=map[i][k];
			}
			int y=i;
			int x=j;
			for(k=0;k<=4;k++) {
				sum3+=map[y-k][x+k];
			}
			for(k=0;k<=4;k++) {
				s3+=map[y-k][x-k];
			}
			for(k=0;k<=4;k++) {
				sum4+=map[y+k][x-k];
			}
			for(k=0;k<=4;k++) {
				s4+=map[y+k][x+k];
			}
			if(sum1 > mx) mx = sum1;
			if(sum2 > mx) mx = sum2;
			if(sum3 > mx) mx = sum3;
			if(sum4 > mx) mx = sum4;
			if(s1 > mx) mx = s1;
			if(s2 > mx) mx = s2;
			if(s3 > mx) mx = s3;
			if(s4 > mx) mx = s4;
		}
	}
	cout<<mx;
}