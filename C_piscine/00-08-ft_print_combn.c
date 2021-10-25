#include <unistd.h>

void ft_putchar(int a)
{
	char c = '0'+a;
	write(1,&c,1);
}

void w(int n,int m)

	
{
if (n>1)
{
	w(n-1,m-1);
	ft_putchar(m-1);

}
}

void ft_print_combn(n)

{

int m;
int u;
int p=0;
int c;
m=n;
u=n;

while (u<11)
{		
w(n+1,m+p);
if (u<10)
{
write(1,",",1);
write(1," ",1);
}
p++;
u++;
}

}
