#include <iostream> 
using namespace std; 
  
  
int main() { 
    int n,i; 
    cin>>n; 
      
    int school[8]; 
    int afterschool[8]; 
    int max=0; 
    int maxvalue=0; 
    for(i=0;i<n;i++) { 
        cin>>school[i]; 
        cin>>afterschool[i]; 
    } 
      
        for(i=0;i<n;i++) { 
          
            if(school[i]+afterschool[i] > 8) { 
            if(maxvalue < school[i]+afterschool[i]) { 
                maxvalue = school[i]+afterschool[i]; 
                max = i+1; 
            } 
            } 
          
    } 
  
    cout<<max; 
      
} 
 
