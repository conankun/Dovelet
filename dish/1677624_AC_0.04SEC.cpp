#include<iostream>
#include<string.h>
using namespace std;
char input[100];
char dishes[100];
int main(){
	char a, b, c, d;
	int longs, i;
	int top=0;
	int now = 0;
	int now2 = 0;
	cin >> input;
	longs = strlen(input);
	char abc = 'a';
	char pushpop[1000];
	while (1){
		now++;
		if (now2 >= longs) break;
		if (dishes[top] != input[now2]){
			if (longs == abc-97){
				printf("impossible");
				return 0;
			}
			else{
				dishes[++top] = abc;
				pushpop[now] = 'u';
				abc++;
			}
		}
		else{
			top--;
			pushpop[now] = 'p';
			now2++;
		}

	}
	for (i = 1; i < now; i++){
		if (pushpop[i] == 'u') printf("push\n");
		else printf("pop\n");
	}
}