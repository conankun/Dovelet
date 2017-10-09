#include<iostream> 
using namespace std; 
int main() { 
    int ax,ay,bx,by,cx,cy; 
    cin>>ax>>ay>>bx>>by>>cx>>cy; 
    if((bx-ax)*(cy-ay) - (by-ay)*(cx-ax) < 0) { 
        cout<<"clock"; 
    } else if((bx-ax) * (cy-ay) - (by-ay)*(cx-ax) > 0) { 
        cout<<"counterclock"; 
    } else cout<<"straight"; 
} 
 
