#include <iostream> 
using namespace std; 
int main() { 
    int ok[10]={0,}; 
    char c[11]={NULL,}; 
    int jari=0; 
    cin>>c; 
    for(int i=0;i<10;i++) { 
        if(c[i] == NULL) break; 
        jari++; 
        ok[(int)c[i]-48-1]++; 
    } 
      
    bool a = true; 
    for(int i=0;i<jari;i++) { 
        if(ok[i] != 1) a=false; 
    } 
  
    a==true?cout<<"yes":cout<<"no"; 
} 
 
