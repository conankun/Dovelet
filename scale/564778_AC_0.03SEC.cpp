#include<stdio.h>
int n,D[999]={1},M[999],s,i,j,m,b;
int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&M[i]);s+=M[i];}
	for(i=1;i<=n;i++){
		for(j=500;j>=0;j--){
			if(D[j])D[j+M[i]]=1;
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		for(j=m;j<=500;j++)if(D[j]&&D[j-m])b=1;
		if(b)printf("Y ");
		else printf("N ");
		b=0;
	}
}