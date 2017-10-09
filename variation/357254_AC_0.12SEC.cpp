#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[101]; 
    cin>>n; 
    float argvsum=0; 
    for(int i=0;i<n;i++)  
    { 
        cin>>arr[i]; 
        argvsum+=arr[i]; 
    } 
    argvsum/=n; 
      
    float sum=0; 
      
    for(int i=0;i<n;i++) { 
        sum+=(arr[i]-argvsum)*(arr[i]-argvsum); 
    } 
      
    printf("%.2f",(float)sum/(float)n); 
      
} 
 
