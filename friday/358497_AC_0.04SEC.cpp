#include<iostream> 
using namespace std; 
int months[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 
int days[7]={0}; 
int main() { 
    int n; 
    cin>>n; 
    int d=0; 
    for(int i=0;i<=n-1;i++) 
    { 
        bool a = false; 
        if((1900+i) %  4 == 0) { 
            if((1900+i) % 100 == 0) { 
                if((1900+i) % 400 == 0) { 
                    a = true; 
                } 
            } else a = true; 
        } 
        if(a) months[1]=29; 
        for(int j=0;j<12;j++) { 
            for(int k=1;k<=months[j];k++) { 
                d++; 
                if(d >= 7) d=0; 
                if(k == 12) days[d]++; 
            } 
        } 
        months[1]=28; 
    } 
    cout<<days[5]<<" "<<days[6]<<" "; 
    for(int i=0;i<5;i++) cout<<days[i]<<" "; 
    //for(int i=0;i<7;i++) cout<<days[i]<<" "; 
} 
 
