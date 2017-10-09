#include<stdio.h>
int a,b,c,d,p,m,g,one,two,three;
char s[4][10]={"none","one","both"};
int main() {
	scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&p,&m,&g);
	if(p%(a+b) <= a && p%(a+b) != 0) one++;
	if(p%(c+d) <= c && p%(c+d) != 0) one++;
	if(m%(a+b) <= a && m%(a+b) != 0) two++;
	if(m%(c+d) <= c && m%(c+d) != 0) two++;
	if(g%(a+b) <= a && g%(a+b) != 0) three++;
	if(g%(c+d) <= c && g%(c+d) != 0) three++;
	printf("%s\n%s\n%s",s[one],s[two],s[three]);
}