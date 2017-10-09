#include <iostream> 
  
using namespace std; 
  
int main() { 
    int n,i; 
    int sum; 
    int nsum=0; 
    cin>>n; 
  
    sum = (n+1)*(n/2) + (n%2==1?n/2+1:0) - n; 
  
    for(i=n+1;nsum<=sum;i++) nsum+=i; 
  
  
    if(nsum-(i-1) == sum) cout<<"O"; 
    else cout<<"X"; 
  
    return 0; 
} 
 
