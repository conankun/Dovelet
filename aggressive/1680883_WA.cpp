#include<iostream>
#include<algorithm>
using namespace std;
int All_stalls[1000000];
int stall, cow, j, yet = All_stalls[1], counte = 1, max_dista = 0;
void bsearche(int left, int right){
	int mid = (left + right) / 2;
	if (left <= right){
		for (j = 2; j <= stall; j++){
			if (All_stalls[j] - yet < mid){
				continue;
			}
			else {
				counte++;
				yet = All_stalls[j];
			}
			if (counte >= cow){
				break;
			}
		}
		if (counte >= cow){
			if (mid > max_dista){
				max_dista = mid;
			}
			bsearche(mid + 1, right);
		}
		else{
			bsearche(left, mid - 1);

		}
	}
}

int main(void) {
	int i;
	scanf("%d %d", &stall, &cow);
	for (i = 1; i <= stall; i++){
		scanf("%d", &All_stalls[i]);
	}
	sort(All_stalls + 1, All_stalls + stall + 1);

	bsearche(All_stalls[1], All_stalls[stall]);
	printf("%d", counte);
}