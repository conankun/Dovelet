#include <iostream> 
using namespace std; 
int main() { 
    char key[27]; 
    char a[81]; 
    char b[81]; 
      
    gets(key); 
    gets(a); 
      
    for(int i=0;;i++) { 
        if(a[i] == NULL) break; 
          
        if(a[i] >= 'A' && a[i] <= 'Z') { 
        //97-65=32 
        b[i] = key[(97+((int)(a[i])-65)-32)-65]-32; 
        } else if(a[i] >= 'a' && a[i] <= 'z') { 
        b[i] = key[(int)a[i]-97]; 
        } else if(a[i] == ' ') { 
        b[i] = ' '; 
        } else break; 
    } 
  
    for(int i=0;;i++) { 
        if(b[i] == '\0') break; 
        else if(b[i] == ' ' || (b[i] >= 'a' && b[i] <='z') || (b[i] >='A' && b[i]<='Z')) cout<<b[i]; 
    } 
  
    //cin>>a; 
} 
 
