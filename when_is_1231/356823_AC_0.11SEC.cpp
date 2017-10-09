#include<iostream> 
using namespace std; 
int mm[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 
int main() { 
    int m,n; 
    int k; 
    int arr[7]; 
    int arr2[7]={0,}; 
    bool a=false; 
    int sum,sum2=0; 
    cin>>m>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    cin>>k; 
  
    for(int j=1;j<=mm[m-1]-(6-arr[0]);j++) { 
        arr2[0]=j; 
        sum2 = j; 
        for(int i=1;i<n;i++) { 
            arr2[i] = j+(arr[i]-arr[0]); 
            sum2+=arr2[i]; 
            if(i == n-1 && sum2 == k) { 
                sum = j; 
                a=true; 
                break; 
            } 
        } 
        if(a) break; 
    } 
  
    int aa=arr[0]; 
    for(int i=arr2[0]-1;i>=1;i--) { 
        aa--; 
        if(aa < 0) aa = 6; 
        //cout<<m<<" "<<i<<":"<<aa<<endl; 
    } 
  
    for(int i=m-1;i>=1;i--) { 
        for(int j=mm[i-1];j>=1;j--) { 
            aa--; 
            if(aa < 0) aa = 6; 
        //  cout<<i<<"/"<<j<<":"<<aa<<endl; 
        } 
    } 
    cout<<aa; 
} 
 
