#include <iostream> 
  
using namespace std; 
int main() { 
    char c[33]; 
    scanf("%s",c); 
    for(int n=1;n<=4;n++) { 
        int a=1; 
        int sum=0; 
        for(int i=8*n-1;i>=8*(n-1);i--) { 
            sum+=a * ((int)(c[i])-48); 
            a*=2; 
        } 
        cout<<sum; 
        if(n != 4) cout<<"."; 
    } 
} 
 
