#include <iostream>
#include <cstring>
using namespace std;
 
int main() {
    char a[4001]={NULL,};
    char b[4001]={NULL,};
    char c[4001]={NULL,};
    int max=0;
    cin>>a>>b;
     
    int asize=0,bsize=0;
    for(int i=0;;i++) {
        if(a[i] == NULL) break;
        else asize++;
    }
 
    for(int i=0;;i++) {
        if(b[i] == NULL) break;
        else bsize++;
    }
 
    for(int i=0;;i++) {
        char d[4001]={NULL,};
        int size=0;
        if(a[i] == NULL) break;
        if(max >= asize) break;
        for(int j=0;;j++) {
            if(b[j] == NULL) break;
            if(a[i] == b[j]) {
                for(int z=0;;z++) {
                    if(a[i+z] != b[j+z]) break;
                    else if(a[i+z] == NULL || b[j+z] == NULL) break;
                    d[size] = a[i+z];
                    size++;
                }
             
                if(size > max) {
                    max = size;
                    strcpy(c,d);
                }
 
                 
                size=0;
             
            }
        }
    }
 
    cout<<max<<endl<<c;
 
}