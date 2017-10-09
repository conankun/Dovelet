#include<iostream> 
#include<memory.h> 
using namespace std; 
struct A { 
	char level[100]; 
	int index; 
}; 
A arr[100000]={0}; 
A imsi[100000]={0}; 
int data[100]; 
int n; 
int main() { 
	cin>>n; 
	for(int i=0;i<n;i++) cin>>data[i]; 
	arr[data[0]].index = 1; 
	arr[data[0]].level[0]='U'; 
	int mx=data[0]; 
	for(int i=1;i<n;i++) { 
		memset(imsi,0,sizeof(A)*100000); 
		int mx2=0; 
		for(int j=mx;j>=0;j--) { 
			if(arr[j].index > 0) { 
				imsi[j+data[i]]=arr[j]; 
				imsi[j+data[i]].level[imsi[j+data[i]].index++]='U'; 
				if(mx2 > j+data[i]) mx2 = j+data[i]; 
				if(j-data[i] >= 0) { 
					imsi[j-data[i]]=arr[j]; 
					imsi[j-data[i]].level[imsi[j-data[i]].index++]='D'; 
				} 
			} 
		} 
		for(int i=0;i<=mx;i++) { 
			arr[i]=imsi[i]; 
		} 
		if(mx2 > mx) mx = mx2; 
	} 
	if(arr[0].index <= 0) { 
		cout<<"IMPOSSIBLE"; 
	} else { 
		for(int i=0;i<arr[0].index;i++) { 
			cout<<arr[0].level[i]; 
		} 
	} 
} 