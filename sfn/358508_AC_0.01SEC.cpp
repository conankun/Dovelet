#include <iostream> 
using namespace std; 
int sum12=0; 
int sum16=0; 
int sum10=0; 
  
void sum12make(int n) { 
    if(n<=0) return; 
    sum12+=n%12; 
    sum12make(n/12); 
    return; 
} 
  
void sum16make(int n) { 
    if(n<=0) return; 
    sum16+=n%16; 
    sum16make(n/16); 
    return; 
} 
  
void sum10make(int n) { 
    if(n<=0) return; 
    sum10+=n%10; 
    sum10make(n/10); 
    return; 
} 
  
int main() { 
      
    for(int i=2991;i<=9999;i++) { 
        sum12=0; 
        sum16=0; 
        sum10=0; 
        sum12make(i); 
        sum16make(i); 
        sum10make(i); 
        if(sum12 == sum16 && sum16==sum10) { 
            cout<<i<<endl; 
        } 
    } 
      
} 
 
