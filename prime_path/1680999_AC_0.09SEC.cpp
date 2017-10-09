#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int starting, finisher, traveler, history, i;
struct prime_searche{
	int il, ship, baek, chun;
	int history;
};
prime_searche fr ,ls;
int isPrime[1111111];
int vis[1111111];
queue<prime_searche> qu;
void divide_increase(int a, prime_searche* ps){
	int chun, baek, ship, il;
	int tempo = a;
	il=tempo % 10;
	tempo /= 10;
	//133
	ship = tempo % 10;
	tempo /= 10;

	baek = tempo % 10;
	tempo /= 10;

	chun = tempo;
	
	prime_searche test;
	test.il = il;
	test.ship = ship;
	test.baek = baek;
	test.chun = chun;

	*ps = test;

	return;
}

int compare_num(prime_searche aaa, prime_searche bbb) {
	if (aaa.il == bbb.il && aaa.ship == bbb.ship && aaa.baek == bbb.baek && aaa.chun == bbb.chun) return 1;
	return 0;
}

int main(void){
	scanf("%d%d", &starting, &finisher);
	
	divide_increase(starting, &fr);
	divide_increase(finisher, &ls);
	fr.history = 0;

	int i, j;
	for (i = 1; i <= 9999; i++) isPrime[i] = 1;
	for (i = 2; i <= 9999; i++) {
		for (j = i * 2; j <= 9999; j += i) {
			isPrime[j] = 0;
		}
	}
	qu.push(fr);
	while (!qu.empty()) {
		if (compare_num(qu.front(), ls)) { //true -> 0 이외의 모든수
			printf("%d", qu.front().history);
			break;
		}
		else {
			prime_searche pr = qu.front();
			vis[pr.chun * 1000 + pr.baek * 100 + pr.ship * 10 + pr.il] = 1;
			prime_searche pr2 = pr;
			pr2.history = pr.history + 1;
			qu.pop();
			for (i = 0; i <= 9; i++){
				if (i != pr.il){
					pr2.il = i;
					if (isPrime[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il] && !vis[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il]) {
						qu.push(pr2);
					}
				}
			}
			pr2 = pr;
			pr2.history = pr.history + 1;
			for (i = 0; i <= 9; i++){
				if (i != pr.baek){
					pr2.baek = i;
					if (isPrime[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il] && !vis[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il]) {
						qu.push(pr2);
					}
				}
			}
			pr2 = pr;
			pr2.history = pr.history + 1;
			for (i = 0; i <= 9; i++){
				if (i != pr.ship){
					pr2.ship = i;
					if (isPrime[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il] && !vis[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il]) {
						qu.push(pr2);
					}
				}
			}
			pr2 = pr;
			pr2.history = pr.history + 1;
			for (i = 1; i <= 9; i++){
				if (i != pr.chun){
					pr2.chun = i;
					if (isPrime[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il] && !vis[pr2.chun * 1000 + pr2.baek * 100 + pr2.ship * 10 + pr2.il]) {
						qu.push(pr2);
					}
				}
			}
		}
	}
}
