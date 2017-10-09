#include<iostream> 
#include<string> 
using namespace std; 
int a = 1; 
int b = 1; 
int main() { 
    string o,t; 
    cin>>o>>t; 
    for(int i=0;i<o.size();i++) { 
        a*=o[i]-'A'+1; 
    } 
    for(int i=0;i<t.size();i++) { 
        b*=t[i]-'A'+1; 
    } 
    a%=47; 
    b%=47; 
    if(a == b) cout<<"GO"; 
    else cout<<"STAY"; 
} 
 
