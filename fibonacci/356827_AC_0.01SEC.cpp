#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[40]={0,}; 
    arr[0]=1; 
    arr[1]=1; 
    for(int i=2;i<40;i++) arr[i]=arr[i-1]+arr[i-2]; 
    int we=2; 
    int hi=1; 
    int count=0; 
    while(cin>>n) { 
        count++; 
        we=2; 
        hi=1; 
        if(n < 2) break; 
        if(n == 2) { 
            cout<<"Case #"<<count<<":"<<endl<<we<<", "<<hi<<endl<<endl; 
            continue; 
        } 
      
        for(int i=2;i<=n-1;i++) { 
        if(we == arr[i]) { 
            hi+=arr[i];  
        } else if(hi == arr[i]) { 
            we+=arr[i]; 
        } 
        } 
  
        cout<<"Case #"<<count<<":"<<endl<<we<<", "<<hi<<endl<<endl; 
    } 
} 
 
