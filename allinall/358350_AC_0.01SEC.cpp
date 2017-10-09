#include<iostream> 
#include<string.h> 
using namespace std; 
int main() { 
    while(1) { 
        char s[100001],t[100001]; 
        if(!(cin>>s>>t)) break; 
        int in=0; 
        int ok=0; 
        for(int i=0;i<strlen(t);i++) { 
            if(t[i] == s[in]) { 
                in++; 
                ok++; 
            } 
        } 
        if(ok == strlen(s)) cout<<"Yes"; 
        else cout<<"No"; 
        cout<<endl; 
    } 
} 
 
