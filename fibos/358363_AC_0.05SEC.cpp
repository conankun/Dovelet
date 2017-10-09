#include <iostream> 
#include <string.h> 
using namespace std; 
char a[21][10001]={NULL,}; 
int main() { 
    int n; 
    cin>>n; 
    cin>>a[0]; 
    cin>>a[1]; 
    cout<<a[0]<<endl<<a[1]<<endl; 
    for(int i=0;i<n-2;i++) { 
        int index=2+i; 
        for(int j=0;j<10000;j++) { 
            if(a[index-2][j] != NULL) cout<<a[index-2][j]; 
        } 
        for(int j=0;j<10000;j++) { 
            if(a[index-1][j] != NULL) cout<<a[index-1][j]; 
        } 
        strcat(a[index],a[index-2]); 
        strcat(a[index],a[index-1]); 
        cout<<endl; 
    } 
} 
 
