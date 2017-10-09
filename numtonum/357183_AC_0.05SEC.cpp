#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int c,cc=0; 
    for(int i=n;i>=1;i--) { 
        int count=2; 
        int lastsu=n; 
        int su=i; 
        while(1) { 
            int temp=lastsu-su; 
            if(temp < 0) break; 
            lastsu = su; 
            su = temp; 
            count++; 
        } 
          
        if(cc < count) { 
            cc = count; 
            c = i; 
        } 
    } 
  
    cout<<cc<<endl; 
    int lastsu=n; 
    int su=c; 
    cout<<lastsu<<" "<<su<<" "; 
    while(1) { 
        int temp = lastsu-su; 
        if(temp < 0) break; 
        cout<<temp<<" "; 
        lastsu = su; 
        su = temp; 
    } 
//  cin>>n; 
} 
 
