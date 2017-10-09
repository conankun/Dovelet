#include <iostream> 
using namespace std; 
int main () { 
    bool day[] = {true,false,true,false,true,false,false}; 
      
    int d; 
    cin>>d; 
      
    if(day[d-1] == true) cout<<"enjoy"; 
    else cout<<"oops"; 
      
    return 0; 
} 
 
