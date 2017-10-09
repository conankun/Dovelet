#include<stdio.h>
int heap[10000];
int r=0,n;
void add_heap() {
	int m=r;
	while(m>1) {
		if(heap[m/2] < heap[m]) {
			heap[m/2]+=heap[m];
			heap[m]=heap[m/2]-heap[m];
			heap[m/2]-=heap[m];
			m/=2;
		} else break;
	}
}
void delete_heap() {
	int m=1;
	while(m<=r) {
		if(heap[m*2] >= heap[m*2+1] && heap[m*2] > heap[m]) {
			heap[m*2]+=heap[m];
			heap[m]=heap[m*2]-heap[m];
			heap[m*2]-=heap[m];
			m=m*2;

		} else if(heap[m*2] < heap[m*2+1] && heap[m*2+1] > heap[m]) {
			heap[m*2+1]+=heap[m];
			heap[m]=heap[m*2+1]-heap[m];
			heap[m*2+1]-=heap[m];
			m=m*2+1;
		} else break;
	}
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=2*n+1;i++) heap[i]=-10000;
	for(i=1;i<=n;i++) {
		scanf("%d",&heap[++r]);
		add_heap();
	}
	for(i=1;i<=n;i++) printf("%d ",heap[i]);
	printf("\n");
	for(i=1;i<=3;i++) {
		heap[1]=heap[r];heap[r]=-10000;r--;
		delete_heap();
	}
	for(i=1;i<=r;i++) printf("%d ",heap[i]);
}