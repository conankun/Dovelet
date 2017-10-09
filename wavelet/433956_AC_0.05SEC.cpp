#include<stdio.h>
#include<deque>
using namespace std;
deque<int> de;
deque<int> imsi;
int n;
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		int a;
		scanf("%d",&a);
		de.push_back(a);
	}
	if(n==1) {
		printf("%d",de[0]);
		return 0;
	}
	int p1=0,p2=1;
	for(i=1;i<=n;i*=2) {
		for(j=0;j<p2-p1;j++) {
			int h=de[p1+j],c=de[p2+j];
			int b,d;
			d = (h-c)/2;
			b = h-d;
			imsi.push_back(b);
			imsi.push_back(d);
		}
		for(i=0;i<imsi.size();i++) de.pop_front();
		while(!imsi.empty()) {
			de.push_front(imsi.back());
			imsi.pop_back();
		}
		p2 += p2-p1;
	}
	for(i=0;i<n;i++) printf("%d ",de[i]);
}