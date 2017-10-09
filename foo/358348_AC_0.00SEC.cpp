#include<iostream> 
using namespace std; 
int main() { 
    while(1) { 
        char c[300]={NULL,}; 
        if(fscanf(stdin,"%s",c)!=EOF) { 
        for(int i=0;i<300;i++) { 
            if(c[i] == NULL) break; 
            if((c[i] == 'F' || c[i] == 'f') && (c[i+1] == 'O' || c[i+1]=='o') && (c[i+2] == 'O' || c[i+2]=='o')) { 
                char t=c[i+2]; 
                c[i+2] = c[i] == 'F'?'F':'f'; 
                c[i] = t=='O'?'O':'o'; 
                i=-1; 
            } 
        } 
        fprintf(stdout,"%s\n",c); 
    } else break; 
    } 
} 
 
