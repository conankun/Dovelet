#include<iostream> 
using namespace std; 
int map[128][128]; 
int white=0,blue=0; 
void Div(int sx,int sy,int n,int size) { 
    int r=map[sy][sx]; 
    bool a=true; 
    for(int i=sy;i<sy+size;i++) { 
        for(int j=sx;j<sx+size;j++) { 
            if(map[i][j] != r) a= false; 
        } 
    } 
      
    if(a) { 
        if(r == 0) white++; 
        else blue++; 
    } else { 
        Div(sx,sy,n,size/2); 
        Div(sx+size/2,sy,n,size/2); 
        Div(sx,sy+size/2,n,size/2); 
        Div(sx+size/2,sy+size/2,n,size/2); 
    } 
} 
int main() { 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>map[i][j]; 
    Div(0,0,n,n); 
    cout<<white<<endl<<blue; 
} 
 
