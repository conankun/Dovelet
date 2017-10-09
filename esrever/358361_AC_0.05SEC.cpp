#include <iostream> 
using namespace std; 
int main() { 
    while(1){ 
        bool a=false; 
        char c[80]={NULL,}; 
        cin>>c; 
        if(c[0] != NULL) { 
        for(int i=79;i>=0;i--) { 
            if(c[i] == NULL) continue; 
            else cout<<c[i]; 
            if(c[i] == '.') a= true; 
        } 
        cout<<" "; 
        if(a == true)break; 
        } else break; 
  
    } 
  
  
  
} 
 
