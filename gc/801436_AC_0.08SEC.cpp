#include <stdio.h>

int main()
{
	int num[20]={0};
	int n,i,j,t,k;

	num[0]=1;
	num[1]=1;
	num[2]=2;

	scanf("%d",&n);
	

	for(i=3;i<=19;i++){
		for(j=0;j<i;j++){
			for(t=i-j-1;t>=0;){
				num[i] += num[j]*num[t];
				break;
			}
		}
	}

	printf("%d",num[n]);
}