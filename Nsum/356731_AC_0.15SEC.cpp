 #include <iostream> 
using namespace std; 
int main () { 
    int n,i; 
    int p=0; 
    cin>>n; 
    for(i=1;i<=100;i++) { 
        p+=i; 
        if(p == n) break; 
    } 
      
    cout<<i; 
    return 0; 
} 
 
