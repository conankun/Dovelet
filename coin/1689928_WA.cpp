#include<iostream>
#include<algorithm>
using namespace std;
long long int mone;
int changes[5]={ 1, 5, 10, 25, 50 };
int real_mone;
int ways[222] = { 0 };

int main(void){
	int i, j;
	scanf("%lld", &mone);
	real_mone = mone * 100;
	ways[0] = 1;
	for (i = 0; i < 5; i++){
		for (j = changes[i]; j <= real_mone; j++){
			ways[j] += ways[j - changes[i]];
		}
	}
	printf("%d", ways[real_mone]);
}