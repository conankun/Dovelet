#include<iostream> 
#include<stdlib.h>
using namespace std; 
int main() {int a,b;long long aa,bb;int n;cin>>n;for(int i=0;i<n;i++) {scanf("%d %d",&a,&b);if(b>a){int c=a;a = b;b = c;}aa = a;bb = b;if(abs(a-b) % 2 == 1) { printf("Scenario #%d:\n%lld\n\n",i+1,(aa+bb) * (aa-bb+1)/2 );} else {printf("Scenario #%d:\n%lld\n\n",i+1,(aa+bb) * (aa-bb)/2 + (aa+bb)/2);}} 
}