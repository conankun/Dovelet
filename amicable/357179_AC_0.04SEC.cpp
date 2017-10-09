#include <iostream> 
#include <cmath> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int arr[10001]; 
    int arrindex=0; 
    for(int i=220;i<=(n < 6999 ? n : 6999);i++) { 
        int sum=1; 
        for(int j=2;j<=sqrt(i);j++) { 
            if(i%j==0)  
            { 
                sum+=j; 
                sum+=i/j; 
            } 
        } 
        //cout<<i<<"-"<<sum<<endl; 
        if(sum != i) { 
        int sum2=1; 
        for(int j=2;j<=sqrt(sum);j++) { 
            if(sum%j == 0)  {  
                sum2+=j; 
                sum2+=sum/j; 
        //      cout<<"j:"<<j<<"sum2:"<<sum2<<endl; 
            } 
        } 
          
        int T = true; 
        for(int a=0;a<=arrindex;a++) { 
            if(arr[a] == sum2) { 
                T = false; 
                break; 
            } 
        } 
          
        if(T) { 
            arr[arrindex++]=sum; 
        if(sum2 == i) 
        { 
            if(i < sum) 
                cout<<i<<" "<<sum<<endl; 
            else
                cout<<sum<<" "<<i<<endl; 
        } 
        } 
        } 
    } 
    return 0; 
} 
 
