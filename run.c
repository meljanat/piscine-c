#include <stdio.h>
#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size);

int main(void)
{
    char str1[] = "Hello World! How are you? This is a test string with non-printable characters: \x01\x02\x03\x04\x05\x06";
    char str2[] = "This is a test string with printable characters: Hello World! hksjd wdhe dwehcue";

    ft_print_memory(str1, sizeof(str1) - 1);
    write(1, "\n", 1);
    ft_print_memory(str2, sizeof(str2));

    return 0;
}