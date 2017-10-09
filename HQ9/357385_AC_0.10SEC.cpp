#include <iostream> 
using namespace std; 
int main () { 
    char source[26]; 
    scanf("%s",source); 
          
    int j=0; 
    for(int i=0;i<26;i++) { 
        if(source[i] == NULL) break; 
        if(j!=0)cout<<endl; 
        if(source[i] == 'H' || source[i] == 'h') { 
            cout<<"Hello, world!"; 
            j++; 
        } else if(source[i] == 'Q' || source[i] == 'q') { 
            cout<<source; 
            j++; 
        } else if(source[i] == '9') { 
            cout<<"99 Bottles of Beer on the Wall"; 
            j++; 
        } 
      
      
    } 
      
    return 0; 
} 
 
