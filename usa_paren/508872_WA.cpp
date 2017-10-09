#include<stdio.h>
#include<stack>
#define mod 12345678910LL
using namespace std;
long long arr[111111],n,sum;
stack<int> st;
int main() {
	scanf("%lld",&n);
	long long i;
	for(i=1;i<=n;i++) scanf("%lld",&arr[i]);
	long long now=0;
	for(i=1;i<=n;i++) {
		if(arr[i]==0) st.push(arr[i]);
		else {
			if(now==0) now=1;
			else now=2*now;
			now%=mod;
			st.pop();
		}
		if(st.empty()) {
			sum+=now;
			sum%=mod;
			now=0;
		}
	}
	printf("%lld",sum);
}