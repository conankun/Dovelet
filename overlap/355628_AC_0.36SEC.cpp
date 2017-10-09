#include<iostream> 
using namespace std; 
int main() { 
    int x1,y1,x2,y2; 
    int x11,y11,x12,y12; 
    cin>>x1>>y1>>x2>>y2; 
    cin>>x11>>y11>>x12>>y12; 
    if( (x1<=x11&&x11<=x2 || x1<=x12&&x12<=x2) || (x11<=x1 && x12>=x2) || (x11>=x2 && x12<=x1)) { 
        if(((y1<=y11 && y11<=y2) || (y1<=y12&&y12<=y2)) || (y11<=y1 && y12>=y2) || (y11>=y2 && y12<=y1)) { 
        cout<<"Overlap"; 
        } else cout<<"No overlap"; 
    } else cout<<"No overlap"; 
} 
 
