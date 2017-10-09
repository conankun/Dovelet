#include <iostream> 
using namespace std; 
int main() { 
    char a[5]; 
    char b[5]; 
    scanf("%s %s",a,b); 
    int aa=0,bb=0; 
    for(int i=0;i<4;i++) { 
        if(a[i] == b[i]) ++aa; 
  
    } 
  
    for(int i=0;i<4;i++) { 
        for(int j=0;j<4;j++) { 
            if(b[i] == a[j] && i!=j) ++bb; 
        } 
    } 
      
    printf("%dA%dB",aa,bb); 
      
} 
 
