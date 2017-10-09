#include <iostream> 
using namespace std; 
int main() { 
    char c[1002]={NULL,}; 
    gets(c); 
    for(int i=1000;i>=0;i--) { 
        if(c[i] == NULL) continue; 
        else
            if(c[i] != ' ') 
            cout<<c[i]; 
    } 
} 
 
