#include <stdio.h>
#include <unistd.h>

void ft_sort_int_tab(int *tab, int size);

int main(void)
{
    int tab[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(tab) / sizeof(tab[0]);
    ft_sort_int_tab(tab, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}