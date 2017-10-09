#include <stdio.h>
int main(void)
{
int i, j;
int kun = -31;
int kkun = -31;
int given[30];
int mx= -62;
for (i = 0; i < 20; i++)
	{
		scanf("%d", &given[i]);
	}
for (i=0;i<20;i++)
{

for (j=i+1; j < 20; j++)
{
if (given[j]> kkun)
{
if (given[i]+given[j]> mx)
mx= given[i]+given[j];
kun= given[i];
kkun = given[j];
}
}
}

printf("%d\n", kun+kkun);
printf("%d %d", kun, kkun);

return 0;
}