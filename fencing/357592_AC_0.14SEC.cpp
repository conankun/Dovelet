#include<iostream>  
#include<cmath>   
#include<algorithm>   
using namespace std;   
struct A { double y,x,index; };   
A arr[10001]={0};   
int vis[10001]={0};   
A list[10001]={0};   
int n,index=0;   
bool c(A a,A b) {   
    if(a.y == b.y) return a.x < b.x;   
    return a.y < b.y;   
}   
  
int main() {   
    cin>>n;   
    for(int i=0;i<n;i++) {   
       cin>>arr[i].x>>arr[i].y;   
    }   
    sort(arr,arr+n,c);   
    vis[0]=1;   
    list[0] = arr[0];   
    for(int i=0;i<n;i++) {   
        arr[i].index = i;   
    }   
    A a=arr[0];   
    do {   
        A b,c;   
        int in=-1;   
        for(int i=1;i<n;i++) {  
            if(arr[i].index != a.index && vis[i] == 0) {   
                b = arr[i];   
                in=i;   
                break;   
            }   
        }   
        if(in == -1) {   
            list[index++]=arr[0];   
            break;   
        }   
        bool tt=false;   
        for(int i=0;i<n;i++) {   
            c = arr[i];   
            if(a.index != c.index && b.index != c.index) {   
                if(((b.x-a.x)*(c.y-a.y) - (b.y-a.y) * (c.x-a.x) < 0 || (b.x-a.x == c.x-b.x && b.y-a.y == c.y-b.y)) && vis[i] != 1) {   
                    b = c;   
                    in=i;   
                    tt=1;   
                }   
            }   
        }   
        bool abc=0;   
            c = arr[0];   
            if(a.index != c.index && b.index != c.index) {   
                if((b.x-a.x)*(c.y-a.y) - (b.y-a.y) * (c.x-a.x) < 0 || (b.x-a.x == c.x-b.x && b.y-a.y == c.y-b.y)) {   
                    b = c;   
                    in=0;   
                    abc=1;   
                }   
            }   
            a = b;   
            vis[in]=1;   
            list[index++] = a;   
            if(abc) break;   
    } while(a.index != 0);   
     
    double sum=0.00; 
    list[index] = list[0]; 
    for(int i=0;i<index;i++) { 
        sum+=sqrt((abs(list[i].x-list[i+1].x)*abs(list[i].x-list[i+1].x) + abs(list[i].y-list[i+1].y)*abs(list[i].y-list[i+1].y))); 
    } 
    printf("%.2f",sum); 
} 
 
