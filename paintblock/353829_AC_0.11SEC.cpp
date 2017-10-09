#include <iostream>
using namespace std;
 
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<( (a*b)-4-( (a-2) * (b-2) ) + (b*c)-4-( (b-2) * (c-2)) + (a*c)-4-( (a-2) * (c-2)) );
 
 
    return 0;
}