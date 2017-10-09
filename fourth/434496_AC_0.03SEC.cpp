#include<stdio.h>
int count1[10000];
int count2[10000];
int x[100],y[100];
int main() {
	int i;
	for(i=1;i<=3;i++) {
		scanf("%d%d",&x[i],&y[i]);
		count1[x[i]]++;
		count2[y[i]]++;
	}
	int x1,y1;
	for(i=1;i<=3;i++) {
		if(count1[x[i]]==1) x1 = x[i];
		if(count2[y[i]]==1) y1 = y[i];
	}
	printf("%d %d",x1,y1);
}