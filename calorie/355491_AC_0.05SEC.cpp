#include <iostream> 
using namespace std; 
int main () { 
    int buger[] = {461,431,420,0}; 
    int drink[] = {130,160,118,0}; 
    int sideorder[] = {100,57,70,0}; 
    int dessert[] = {167,266,75,0}; 
    int a,b,c,d; 
    cin>>a>>b>>c>>d; 
      
    cout<<"Your total Calorie count is "<<buger[a-1]+drink[b-1]+sideorder[c-1]+dessert[d-1]<<"."; 
    return 0; 
} 
 
