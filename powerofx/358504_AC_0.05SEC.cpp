#include <iostream> 
  
using namespace std; 
  
int main() { 
int n,s,sum=1; 
cin>>n>>s; 
for(int i=0;i<s;i++,sum*=n); 
cout<<sum; 
return 0; 
} 
 
