#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b) {
	return a > b;
}
int n;
int arr[10000];
int main() {
	cin>>n;
	int i;
	for(i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int turn=1; //0 오름차순, 1 내림차순.
	for(i=1;i<n-1;i++) {
		if(turn == 0) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		} else {
			if(arr[i] < arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		turn = 1-turn;
	}
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
}