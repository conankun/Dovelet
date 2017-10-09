#include<stdio.h>
int n,D[600][600],w[600][3],i,j,k;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d%d",&w[i][0],&w[i][1],&w[i][2]);
	D[0][0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			D[i][j]%=1000;
			for(k=i+1;k<n;k++){
				if(w[i][1]>=w[k][0]-w[i][0]) D[k][j]+=D[i][j];
				if(w[k][1]>=w[k][0]-w[j][0]&&w[j][2]==1&&w[k][2]==1) D[i][k]+=D[i][j];
			}
		}
		for(j=i+1;j<n;j++){
			D[i][j]%=1000;
			for(k=j+1;k<n;k++){
				if(w[i][1]>=w[k][0]-w[i][0]) D[k][j]+=D[i][j];
				if(w[k][1]>=w[k][0]-w[j][0]&&w[j][2]==1&&w[k][2]==1) D[i][k]+=D[i][j];
			}
		}
	}
	for(k=0;k<n-1;k++){
		if(w[n-1][0]-w[k][0]<=w[n-1][1]) D[n-1][n-1]+=D[n-1][k];}
	printf("%d\n",D[n-1][n-1]%1000);
	return 0;
}