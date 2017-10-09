#include<iostream>
using namespace std;
int dp[2][200][200]; //0 - 악마의 돌다리, 1 - 천사의 돌다리 , j - j번째 돌다리 k-k번째문자열을 맞출때.
char mari[100];
int marisize=0;
char dell[200];
int dellsize=0;
char chon[200];
int main() {
	int i,j,k;
	scanf("%s\n",&mari[1]);
	scanf("%s\n",&dell[1]);
	scanf("%s",&chon[1]);
	for(i=1;;i++) {
		if(!mari[i]) break;
		marisize++;
	}
	for(i=1;;i++) {
		if(!dell[i]) break;
		dellsize++;
	}
	for(i=1;i<=dellsize;i++) {
		if(dell[i] == mari[1]) {
			dp[0][i][1]=1;
		}
		if(chon[i] == mari[1]) {
			dp[1][i][1]=1;
		}
	}
	for(i=1;i<=dellsize;i++) {
		for(j=1;j<=i-1;j++) {
			for(k=1;k<=marisize-1;k++) {
				if(dp[0][j][k] > 0 && chon[i] == mari[k+1]) {
					dp[1][i][k+1]+=dp[0][j][k];
				}
				if(dp[1][j][k] > 0 && dell[i] == mari[k+1]) {
					dp[0][i][k+1]+=dp[1][j][k];
				}
			}
		}
	}
	int sum=0;
	for(i=1;i<=dellsize;i++) {
		sum+=dp[0][i][marisize];
		sum+=dp[1][i][marisize];
	}
	cout<<sum;
}