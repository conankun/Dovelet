#include <stdio.h>
void pTp(int n){
	if (n == 1){
		printf("%d", n);
		return;
	}
	else{
		pTp(n - 1);
		printf("%d", n);
		pTp(n - 1);
	}

}


int main()
{
	int n;
	scanf("%d", &n);
	pTp(n);
}
