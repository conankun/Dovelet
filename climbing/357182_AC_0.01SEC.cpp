#include <iostream> 
using namespace std; 
int main() { 
    int a,b,c; 
    while(cin>>a>>b>>c) { 
        if(a == 0 && b == 0 && c == 0) break; 
        else { 
            int l=0; 
            int n=0; 
            for(int i=1;;i++) { 
                if(l >= a) break; 
                else { 
                    if(i%2 == 1) { 
                        l+=b; 
                        n++; 
                    } else { 
                        l-=c; 
                        n++; 
                    } 
                } 
            } 
            cout<<n<<endl; 
        } 
    } 
    return 0; 
} 
 
