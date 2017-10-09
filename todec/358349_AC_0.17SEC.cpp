#include <iostream> 
using namespace std; 
int main() { 
    char c[50]; 
    scanf("%s",c); 
      
    int csize=0; 
    for(int i=0;i<50;i++) { 
        if((int)c[i] != 0) csize++; 
        else break; 
    } 
      
    int sum=0; 
    int gob=1; 
    for(int i=csize-1;i>=0;i--) { 
        sum+= gob * (((int)c[i])-48); 
        gob*=2; 
    } 
      
    cout<<sum; 
      
} 
 
