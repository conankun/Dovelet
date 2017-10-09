#include<iostream> 
#include<string.h> 
using namespace std; 
char a[1000]={0},b[1000]={0},c[1000]={0},d[1000]={0},e[1000]={0},f[1000]={0}; 
char sum[1000]={0}; 
int main() { 
    char input[1000]={0}; 
    scanf("%s",input); 
    bool t=false,t2=false; 
    int ain=0,bin=0,cin=0; 
    for(int i=0;i<strlen(input);i++) { 
        if(input[i] == '+') { 
            t=true; 
        } else if(input[i] == '=') { 
            t2=true; 
        } else { 
            if(t2) { 
                c[cin++]=input[i]; 
            } else if(t) { 
                b[bin++]=input[i]; 
            } else { 
                a[ain++]=input[i]; 
            } 
        } 
    } 
    int in=0; 
    bool ab=false; 
    for(int i=strlen(c)-1;i>=0;i--) { 
        if(!ab && c[i] == '0') { 
            continue; 
        }  
        if(c[i] != '0' || ab) { 
            f[in++] = c[i]; 
            ab=true; 
        } 
    } 
    if(c[0] == '0' && c[1] == 0) { 
        f[0]='0'; 
    } 
    in=0; 
    for(int i=0;i<max(strlen(a),strlen(b));i++) { 
        if(a[i] == 0) { 
            sum[in]+=b[i]-48; 
        } else if(b[i] == 0) { 
            sum[in]+=a[i]-48; 
        } else { 
            if(sum[in]+a[i]-48 + b[i]-48 > 10) { 
                sum[in] += a[i]-48+b[i]-48; 
                sum[in] = sum[in]%10; 
                sum[in+1]++; 
            } else { 
                sum[in] += a[i]-48+b[i]-48; 
                if(sum[in] >= 10) { 
                    sum[in] = sum[in]%10; 
                    sum[in+1]++; 
                } 
            } 
        } 
        in++; 
    } 
    t=true; 
    for(int i=100;i>=0;i--) { 
        if(sum[i] != 0) { 
            in = i; 
            break; 
        } 
    } 
    for(int i=0;i<max(strlen(sum),strlen(f));i++) { 
        if(in == -1) { 
            if(f[i] != 0) { 
                t=false; 
            } 
            break; 
        } 
        if(f[i] != sum[in--]+48) { 
            t=false; 
            break; 
        } 
    } 
    if(t) cout<<"True"; 
    else cout<<"False"; 
} 
 
