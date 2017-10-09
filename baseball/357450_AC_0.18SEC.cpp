#include <stdio.h> 
  
  
struct Ball { 
  
     char balls[3]; 
  
     int strike,ball; 
  
}; 
  
  
int main() { 
  
int n; 
int ii; 
char i,j,z; 
int count=0,outputcount=0; 
Ball youngsubal[101]; 
  
  
  
scanf("%d",&n); 
  
  
  
for(ii=0;ii<n;ii++) 
{ 
scanf("%s %d %d",youngsubal[ii].balls,&youngsubal[ii].strike,&youngsubal[ii].ball); 
} 
  
for(i='1';i<='9';i+=1) { 
  
    for(j='1';j<='9';j+=1) { 
  
       for(z='1';z<='9';z+=1) { 
 if(i == j || i == z || j == z) continue; 
 count=0; 
 char su[3]; 
 su[0] = i; 
 su[1] = j; 
 su[2] = z; 
    for(ii=0;ii<n;ii++) { 
   
 int c,d; 
    int strike=0,ball=0; 
   
 for(c=0;c<3;c++) { 
  for(d=0;d<3;d++) { 
   if(youngsubal[ii].balls[c] == su[d] && c==d) strike++; 
   else if(youngsubal[ii].balls[c] == su[d] && c != d) ball++; 
  } 
 } 
 if(strike == youngsubal[ii].strike && ball == youngsubal[ii].ball) { 
  count++; 
  continue; 
 } else continue; 
 } //ii. 
  
if(count == n) outputcount++; 
  
}//z 
}//j 
}//i 
  
printf("%d",outputcount); 
  
  
 return 0; 
} 
 
