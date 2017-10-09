#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
long long n;
long long graph[1000000];
long long sums[1000000];
struct A {
	long long height;
	long long g;
};
stack<A> st;
stack<A> st2;
int main() {
	long long i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) {
		scanf("%lld",&graph[i]);
	}
	for(i=1;i<=n;i++) {
		long long sum=0;
		while(!st.empty()) {
			if(st.top().height >= graph[i]) {
				sum+=st.top().g+1;
				st.pop();
			} else break;
		}
		sums[i]+=sum;
		A a;
		a.height = graph[i];
		a.g = sum;
		st.push(a);
	}
	for(i=n;i>=1;i--) {
		long long sum=0;
		while(!st2.empty()) {
			if(st2.top().height >= graph[i]) {
				sum+=st2.top().g+1;
				st2.pop();
			} else break;
		}
		sums[i]+=sum;
		A a;
		a.height = graph[i];
		a.g = sum;
		st2.push(a);
	}
	long long mx=0;
	for(i=1;i<=n;i++) {
		if(graph[i]*(sums[i]+1) > mx) mx = graph[i]*(sums[i]+1);
	}
	printf("%lld",mx);
}