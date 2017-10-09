 #include <iostream> 
using namespace std; 
int main () { 
    int n; 
    int a=0; 
    cin>>n; 
    for(int i=1;i<=n;i++)  
    {    
        cout<<i; 
        if(i != n) cout<<"+"; 
          
        a+=i; 
    } 
    cout<<"="<<a; 
    return 0; 
} 
 
