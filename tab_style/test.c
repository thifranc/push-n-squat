#include <stdlib.h>
#include <stdio.h>

int		main()
{
	int		**tab;
	int		i;

	i = 0;

	tab = malloc(sizeof(int*) * 4);
	tab[0] = malloc(sizeof(int));
	tab[1] = malloc(sizeof(int));
	tab[2] = malloc(sizeof(int));
	tab[3] = malloc(sizeof(int));
	*tab[0] = 3;
	*tab[1] = 4;
	tab[2] = NULL;
	*tab[3] = 0;
	while (tab[i])
	{
		printf("%d\n", *tab[i]);
		i++;
	}
	tab[2] = tab[1] + 1;
	*tab[2] = 5;
	tab[2 + 1] = NULL;
	i = 0;
	while (tab[i])
	{
		printf("%d\n", *tab[i]);
		i++;
	}
}//trop dur de faire push swap de cette maniere ? ya moyen
