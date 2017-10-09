#include <iostream> 
using namespace std; 
int fact[]={1,1,2,6,24,120,720,5040,40320,362880}; 
  
  
int main () { 
    int i; 
    for(int a=100;a<=1000000;a++) { 
        int sum=0; 
          
        for(i=100;a>=i;i*=10); 
        i/=10; 
          
          
        for(int j=i;j>=1;j/=10) { 
            if(i == a) { 
                if(j == a) sum+=fact[1]; 
                else sum+=fact[0]; 
            } else { 
                if(j == i) { 
                    sum+=fact[a/j]; 
                } else { 
                    sum+=fact[(a-((a/(j*10))*(j*10)))/j]; 
                } 
            } 
        } 
          
          
        if(sum == a) 
            cout<<a<<endl; 
          
        sum=0; 
    } 
  
      
      
    return 0; 
} 
 
