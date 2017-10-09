#include <stdio.h>
int main(void)
{
int i, j;
int kun = -31;
int kkun = -31;
int given[30];
for (i = 0; i < 20; i++)
	{
		scanf("%d", &given[i]);
	}
for (i=0;i<20;i++)
{
if (given[i]> kun)
{
kun = given[i];
}
for (j=i+1; j < 20; j++)
{
if (given[i]> kkun && given[i] != kun)
{
kkun = given[i];
}
}
}
printf("%d\n", kun+kkun);
printf("%d %d", kun, kkun);

return 0;
}