#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int max=0; 
    for(int i=1;i<=n;i++) { 
        int lastsu=n; 
        int nowsu=i; 
        int h=2; 
        for(;;) { 
            int temp=nowsu; 
            nowsu=lastsu-nowsu; 
            lastsu=temp; 
            h++; 
            if(lastsu-nowsu < 0) break; 
        } 
        if(h > max) max = h; 
    } 
    cout<<max; 
    return 0; 
} 
 
