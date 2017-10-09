#include<iostream> 
using namespace std; 
int main() { 
    while(1) { 
        char c[100]={0}; 
        cin>>c; 
        if(c[0] == '0') break; 
        bool t=true; 
        for(int i=1;;i++) { 
            if(c[i] == 0) break; 
            else { 
                if(c[i] > c[i-1]) t=false; 
            } 
        } 
        if(t) { 
            cout<<"no bouncy"<<endl; 
            continue; 
        } 
        t=true; 
        for(int i=1;;i++) { 
            if(c[i] == 0) break; 
            else { 
                if(c[i] < c[i-1]) t=false; 
            } 
        } 
        if(t) { 
            cout<<"no bouncy"<<endl; 
        } else { 
            cout<<"bouncy"<<endl; 
        } 
    } 
} 
 
