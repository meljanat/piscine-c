void	ft_rev_int_tab(int *tab, int size)
{
	int start = 0;
	while (start < size / 2)
	{
		int temp = tab[start];
		tab[start] = tab[size - start - 1];
		tab[size - start - 1] = temp;
		start++;
	}
}