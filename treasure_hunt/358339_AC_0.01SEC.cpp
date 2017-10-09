#include<iostream> 
using namespace std; 
int a,b; 
int na=0,nb=0; 
int n; 
int main() { 
    cin>>a>>b; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        int c; 
        char d; 
        cin>>c>>d; 
        switch(d) { 
        case 'N':nb+=c;break; 
        case 'S':nb-=c;break; 
        case 'E':na+=c;break; 
        case 'W':na-=c;break; 
        } 
    } 
    if(na == a && nb == b) { 
        cout<<"Treasure Found"; 
    } else cout<<"Bad Map"; 
  
} 
 
