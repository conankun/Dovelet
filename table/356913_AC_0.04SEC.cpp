#include <iostream> 
using namespace std; 
int main() { 
    unsigned long long n; 
    cin>>n; 
    unsigned long long a=n; 
    for(unsigned long long i=1;i<10;i++) a*=n; 
      
    unsigned long long jari=1; 
    unsigned long long b; 
    for(b=1;;b++) { 
        jari*=10; 
        if(jari > a) break; 
    } 
      
    for(unsigned long long c=0;c<=10;c++) { 
        if(c == 0) for(unsigned long long ij=0;ij<=b;ij++) cout<<" "; 
        else { 
            if(c != 10) for(unsigned long long ij=0;ij<=b-1;ij++) cout<<" "; 
            else for(unsigned long long ij=0;ij<=b-2;ij++) cout<<" "; 
        } 
        if(c != 0) cout<<c; 
    } 
    cout<<endl; 
    for(unsigned long long i=2;i<=n;i++) { 
        for(unsigned long long ii=0;ii<b;ii++) cout<<" "; 
        cout<<i; 
        for(unsigned long long ii=0;ii<b;ii++) cout<<" "; 
        cout<<i; //9이하이므로 괜히 공백 줄임처리 필요없음. 
          
        for(unsigned long long ij=2;ij<=10;ij++) { 
            unsigned long long su=i; 
            for(unsigned long long iii=0;iii<ij-1;iii++) su*=i; 
              
            unsigned long long j; 
            unsigned long long jari=1; 
            for(j=0;j<ij;j++) { 
                if(jari > su) break; 
                jari*=10; 
            } 
              
            for(unsigned long long g=0;g<=b-j;g++) cout<<" "; 
            cout<<su; 
        } 
        cout<<endl; 
          
    } 
      
    return 0; 
} 
 
