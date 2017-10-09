#include <stdio.h> 
  
int main (){ 
    for(char a='A';a<='Z';a++) { 
        for(char b = 'A'; b<='Z';b++) { 
            for(char c = 'A'; c <='Z';c++) { 
                printf("%c%c%c ",a,b,c); 
            } 
        } 
    } 
    return 0; 
} 
 
