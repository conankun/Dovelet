#include<stdio.h>
#include<math.h>
int n;
int goal;
int input[1000000];
int numbers[1000000];
int eq;
void searche(int left, int right){
	if (left > right){
		return;
	}
	int i;
	int mid = (left + right) / 2;
	int sum = 0;
	
	for (i = 1; i <= mid; i++){
		sum += numbers[i];
	}
	if (sum >= goal){
		searche(left, mid - 1);
		if (eq == 0 || eq > mid) eq = mid;
		return;
	}
	for (i = mid + 1; i <= n; i++){
		sum = sum + numbers[i] - numbers[i - mid];
		if (sum >= goal){
			searche(left, mid - 1);
			if (eq == 0 || eq > mid) eq = mid;
			return;
		}
	}
	searche(mid + 1, right);

}



int main(){
	int i, max = -1, difs = 1000000;
	scanf("%d %d", &n, &goal);
	for (i = 1; i <= n; i++){
		scanf("%d", &numbers[i]);
	}
	searche(1, n);
	printf("%d", eq);
}
