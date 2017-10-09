#include<iostream>
#include<algorithm>
using namespace std;
float mone;
int changes[5]={ 1, 5, 10, 25, 50 };
int real_mone;
int ways[222] = { 0 };

int main(void){
	int i, j;
	scanf("%g", &mone);
	real_mone = mone * 100;
	ways[0] = 1;
	for (i = 0; i < 5; i++){
		for (j = changes[i]; j <= real_mone; j++){
			ways[j] += ways[j - changes[i]];
		}
	}
	cout<< ways[real_mone];
}