#include <iostream> 
using namespace std; 
int d[100];
int main () { 
int n; 
cin>>n; 
int i;
d[0]=0;
d[1]=1;
for(i=2;i<=n;i++) d[i] = d[i-1]+d[i-2];
cout<<d[n]; 
return 0; 
}