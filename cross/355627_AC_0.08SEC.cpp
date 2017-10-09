#include <iostream> 
using namespace std; 
  
int main() { 
    int a,b; 
    int c,d; 
    cin>>a>>b; 
    cin>>c>>d; 
  
    int point1,point2; 
    if(a>b?a:b + ((a-b)*-1 ) > 100) { 
        if(a<b) point1 = a; else point1 = b; 
  
        if(a>b) point2 = a; else point2 = b; 
  
        if(((c>=point2 && c<=100) || (c<point1 && c>=1) )) { 
            if(((d>=point2 && d<=100) || (d<=point1 && d>=1) )) { 
                cout<<"not cross"; 
            } else { 
                cout<<"cross"; 
            } 
            return 0; 
        } else if((d>=point2 && d<=100) || (d<=point1 && d>=1)) { 
  
            if(((c>=point2 && c<=100) || (c<=point1 && c>=1) )) { 
                cout<<"not cross"; 
            } else { 
                cout<<"cross"; 
            } 
            return 0; 
        } 
    } else { 
        if(a<b) point1 = a; else point1 = b; 
        if(a>b) point2 = a; else point2 = b; 
  
        if( ( c >= point1 && c<= point2)) { 
            if((d >= point1 && d <= point2)) { 
                cout<<"not cross"; 
            } else { 
                cout<<"cross"; 
            } 
  
  
            return 0; 
        } else if( (d >= point1 && d <= point2) ) { 
            if((c >= point1 && c <= point2)) { 
                cout<<"not cross"; 
            } else { 
                cout<<"cross"; 
            } 
            return 0; 
        } 
    } 
  
    cout<<"not cross"; 
  
    return 0; 
} 
 
