#include <iostream> 
using namespace std; 
int main() { 
    int a,b; 
    int bb,dd; 
    int c,d; 
    int cc; 
    int bunja,bunmo; 
    int bunja2,bunmo2; 
    cin>>a>>b; 
    cin>>c>>d; 
  
    bb = b; 
    dd = d; 
  
    int gob=b*d; 
    do { 
        cc = b % d; 
        b = d; 
        d = cc; 
    }while(cc !=0); 
  
    //cout<<gob/b; 
  
  
    a = a * ((gob/b)/bb); 
  
    c = c * ((gob/b)/dd); 
  
    bunmo = gob/b; 
    bunja = a+c; 
  
    bunja2 = bunmo-bunja; 
    bunmo2 = bunmo; 
    int ccc; 
    do { 
        ccc = bunja % bunmo; 
        bunja = bunmo; 
        bunmo = ccc; 
    }while(ccc != 0); 
  
    if(bunja2 != 0) 
    cout<<(bunja2/bunja)<<"/"<<bunmo2/bunja; 
    else
    cout<<"0"; 
    return 0; 
} 
 
