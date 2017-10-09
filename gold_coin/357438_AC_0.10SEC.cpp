#include <iostream> 
  
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
      
    int sum=0; 
      
    int pivot=1; 
    int doit=0; 
      
    for(int i=0;i<n;i++) { 
        sum+=pivot; 
        doit++; 
        if(doit == pivot) { 
            pivot++; 
            doit=0; 
        } 
    } 
      
    cout<<n<<" "<<sum; 
      
} 
 
