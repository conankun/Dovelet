#include<iostream>
#include<algorithm>
using namespace std;
int n,c;
int barn[1000000];
int chk[1000000];
int mn=999999999;
int ind=-1;
void search(int low,int high) {
	int mid = (low+high)/2;
	if(low<=high) {
		if(chk[low] == 1 && chk[high] == 1) {
			if(chk[mid] == 1) {
				search(low,mid-1);
				search(mid+1,high);
			} else {
				if(min(abs(barn[high]-barn[mid]),abs(barn[low]-barn[mid])) < mn) {
					mn = min(abs(barn[high]-barn[mid]),abs(barn[low]-barn[mid]));
					ind = mid;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&c);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&barn[i]);
	sort(barn+1,barn+1+n);
	if(n == 2) {
		printf("%d",barn[n]-barn[1]);
		return 0;
	}
	chk[1]=1;
	chk[n]=1;
	for(i=3;i<=c;i++) {
		mn=99999999;
		ind=-1;
		search(1,n);
		if(ind != -1) {
			chk[ind]=1;
		}
	}
	int before=1;
	int mins=999999999;
	for(i=2;i<=n;i++) {
		if(chk[i] == 1) {
			if(barn[i]-barn[before] < mins) mins = barn[i]-barn[before];
		}
	}
	printf("%d",mins);
}