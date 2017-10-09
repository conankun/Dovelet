#include <stdio.h>
int main(void){
	long long int p, y, gcm, lcd, gop, i, hap, dduk, duk, c, d, bp2, by;
	scanf("%lld %lld", &gcm, &lcd);
	gop = lcd / gcm;
	hap = -1;
	p = 1;
	y = 1;

	
	for (i = 1; i*i <= gop; i++){
		p = gop / i;
		y = i;
		bp2 = p;
		by = y;
		d = bp2*by;
		do{
			c = bp2%by;
			bp2 = by;
			by = c;
		} while (c != 0);
		if (bp2 == 1 && bp2* d == gop){
			if (p + y < hap || hap == -1){
				hap = p + y;
				dduk = p;
				duk = y;
			}
		}
	}
	printf("%lld %lld", duk*gcm, dduk*gcm);
	return 0;
}