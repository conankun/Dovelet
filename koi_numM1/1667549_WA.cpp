#include <stdio.h>
int main(void){
	long long int p, y, gcm, lcd, gop, i, hap;
	scanf("%lld %lld", &gcm, &lcd);
	gop = lcd / gcm;
	hap = -1;
	p = 1;
	y = 1;
	for (i = 1; i*i <= gop; i++){
		p = gop / i;
		y = i;
		if (p + y < hap || hap == -1){
			hap = p + y;
		}
	}
	printf("%lld %lld", y*gcm, p*gcm);
	return 0;
}