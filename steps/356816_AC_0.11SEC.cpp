#include<iostream> 
using namespace std; 
int main() { 
    int x,y; 
    cin>>x>>y; 
    int t=1; 
    int value=0; 
    for(int i=1;i<=y;i++) { 
        if(t % 2 == 0) { 
            value+=3; 
        } else { 
            value+=1; 
        } 
        t++; 
        if(x == i && y == i) { 
            cout<<value; 
            return 0; 
        } 
    } 
    t=1; 
    value=2; 
    for(int i=3;i<=5000;i++) { 
        if(t % 2 == 0) value+=3; 
        else value+=1; 
        t++; 
        if(x == i && y == i-2) { 
            cout<<value; 
            return 0; 
        } 
    } 
    cout<<"No Number"; 
} 
 
