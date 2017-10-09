#include <iostream> 
using namespace std; 
  
int main() { 
    int a,b; 
    int j; 
    cin>>a>>b; 
  
    int max=0; 
  
    for(int i=((a>b?b:a)%2 == 0?(a>b?b:a)+1:(a>b?b:a));i<=(a<b?b:a);i+=2) { 
        int count=0; 
        for(j=i;;) { 
            if(j == 1) break; 
            if(j%2 == 0) j/=2; 
            else if(j%2 == 1) j = j*3 + 1; 
            count++; 
        } 
  
        if(count > max)max = count; 
    } 
  
  
    cout<<max+1; 
  
    return 0; 
  
} 
 
