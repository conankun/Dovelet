#include<stdio.h>
#include<stack>
using namespace std;
int N;
stack<int> st1,st2,st3;
int main() {
	scanf("%d",&N);
	int i;
	for(i=N;i>=1;i--) st1.push(i);
	int a,b;
	while(scanf("%d%d",&a,&b) != -1) {
		if(a==1) {
			for(i=1;i<=b;i++) {
				st2.push(st1.top());
				st1.pop();
			}
		} else {
			for(i=1;i<=b;i++) {
				st3.push(st2.top());
				st2.pop();
			}
		}
	}
	while(!st3.empty()) {
		printf("%d\n",st3.top());
		st3.pop();
	}
}