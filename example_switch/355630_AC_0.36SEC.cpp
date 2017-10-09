#include <iostream> 
using namespace std; 
int main() { 
    int y,m; 
    cin>>y>>m; 
      
    if(m == 2) { 
        if(y % 4 == 0) { 
            if(y % 100 == 0) { 
                if(y % 400 == 0) { 
                    cout<<"29"; 
                } else { 
                    //no 
                    cout<<"28"; 
                } 
            } else { 
                //YES 
                cout<<"29"; 
            } 
        } else { 
            //NO 
            cout<<"28"; 
        } 
    } else if(m == 1 || m == 3 || m == 5 ||m == 7 || m == 8 ||m == 10||m==12) { 
        cout<<"31"; 
    } else { 
        cout<<"30"; 
    } 
} 
 
