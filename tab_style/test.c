#include <stdlib.h>
#include <stdio.h>

void	swapp(int **tab, int nb1, int nb2)
{
	int		*back;

	back = tab[nb1];
	tab[nb1] = tab[nb2];
	tab[nb2] = back;
}

void	print_tab(int **tab)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		dprintf(1, "nb=%d, rank=%d\n", *tab[i], i);
		i++;
	}
}

int		main(void)
{
	int		**tab;

	tab = (int**)malloc(sizeof(int*) * 2);
	tab[0] = (int*)malloc(sizeof(int));
	tab[1] = (int*)malloc(sizeof(int));
	*(tab[0]) = 5;
	*(tab[1]) = 9;
	print_tab(tab);
	swapp(tab, 0, 1);
	print_tab(tab);
	free(tab[0]);
	free(tab[1]);
	free(tab);//0 leaks tested with valgrind
	return (0);
}
