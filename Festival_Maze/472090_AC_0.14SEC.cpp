#include<stdio.h>
int p[10000000];
int order[1000000];
int a[10000],b[10000];
int n;
int ind;
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++) order[a[i]]=i;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n-1;j++) {
			if(order[b[j]] > order[b[j+1]]) {
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				p[++ind]=j;
			}
		}
	}
	for(i=1;i<=ind;i++) printf("%d %d\n",p[i],p[i]+1);
}