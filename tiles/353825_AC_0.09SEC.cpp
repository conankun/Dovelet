#include <iostream>
using namespace std;
int main () {
    int a,b;
    int pt=0,ptb=0;;
    cin>>a>>b;
 
    pt = (a % 8 != 0 ? 1:0) * (((a % 8 != 0 ? 1:0) * (b/8)) + ( b%8 == 0 ? 0 : 1 ));
           
    ptb = (b%8 != 0 ? 1:0) * (((b%8 != 0 ? 1:0)* (a/8) ) + ( (a-(a%8))%8 == 0 ?  0:1 ));
     
     
    //cout<<a<<endl<<a%8<<endl<<a-(a%8)<<endl<<(a-(a%8))/8<<endl;
    //cout<<pt<<endl<<ptb<<endl;
     
    printf("The number of whole tiles is %d part tiles is %d",(a/8)*(b/8),pt+ptb);
    return 0;
}