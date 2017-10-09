#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int i;
	int now=0;
	int sum=0;
	for(i=0;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		int t=now-b;
		if(t < 0) t=0;
		if(b > now)
		now = b+c;
		else
		now = now+c;
		sum+=t;
	}
	printf("%.1f",sum/(double)n);
}