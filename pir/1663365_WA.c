#include <stdio.h>
int main(void)
{
int i, j;
int kun = -31;
int kkun = -31;
int given[20];
for (i=1;i<20;i++)
{
if (given[i]> kun)
{
kun = given[i];
}
for (j=i+1; i < 20; i++)
{
if (given[i]> kkun)
{
kkun = given[i];
}
}
}
printf("%d\n", kun+kkun);
printf("%d %d", kun, kkun);

return 0;
}