#include<stdio.h>
#include<deque>
#include<algorithm>
using namespace std;
int n;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int i,j;
	while(scanf("%d",&n) != -1) {
		if(n==0) break;
		int oven[4]={0};
		int cakes[100]={0};
		for(i=1;i<=n;i++) scanf("%d",&cakes[i]);
		sort(cakes+1,cakes+1+n,cmp);
		deque<int> de;
		for(i=1;i<=n;i++) de.push_back(cakes[i]);
		for(i=0;i<=2000;i++) {
			int count=0;
			for(j=1;j<=3;j++) {
				if(oven[j] > 0) oven[j]--;
				if(oven[j] == 0) {
					if(!de.empty()) {
						oven[j]=de.front();
						de.pop_front();
					} else {
						count++;
					}
				}
			}
			if(count ==3) {
				printf("%d\n",i);
				break;
			}
		}
	}
}