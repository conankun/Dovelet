#include<iostream> 
using namespace std; 
int main() { 
    int a,b,c,d; 
    cin>>a>>b>>c>>d; 
    int max=0; 
    int maxp=0; 
  
      
  
    if((a*((double)d/a)) * (b*((double)d/a)) > max && (a*((double)d/a)) * (b*((double)d/a)) <= c*d) { 
        max = (a*((double)d/a)) * (b*((double)d/a)); 
        maxp = ((double)d/a)*100; 
    } 
    if((a*((double)c/b)) * (b*((double)c/b)) > max && (a*((double)c/b)) * (b*((double)c/b)) <=c*d) { 
        max = (a*((double)c/b)) * (b*((double)c/b)); 
        maxp = ((double)c/b)*100; 
    } 
    if((a*((double)c/a)) * (b*((double)c/a)) > max && (a*((double)c/a)) * (b*((double)c/a)) <=c*d) { 
        max = (a*((double)c/a)) * (b*((double)c/a)); 
        maxp = ((double)c/a)*100; 
    } 
    if((a*((double)d/b)) * (b*((double)d/b)) > max && (a*((double)d/b)) * (b*((double)d/b))<=c*d) { 
        max = (a*((double)d/b)) * (b*((double)d/b)); 
        maxp = ((double)d/b)*100; 
    } 
    printf("%d%%",maxp<=100?maxp:100); 
} 
 
