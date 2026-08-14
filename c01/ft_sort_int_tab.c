void	ft_sort_int_tab(int *tab, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				int temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
}