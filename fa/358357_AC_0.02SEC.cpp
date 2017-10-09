#include <iostream> 
using namespace std; 
char c[102]; 
int a[26]; 
int main() { 
    cin>>c; 
    for(int i=0;i<100;i++) { 
        a[((int)c[i])-((int)'a')]++; 
    } 
    for(int i=0;i<26;i++) { 
        printf("%c:%d\n",(char)(i+97),a[i]); 
    } 
  
} 
 
