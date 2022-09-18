#include "test.h"

int	main(void)
{
	ft_printf("Valor: %d\n", 42);
	ft_printf("Valor2: %s\n", "teste");


	int idade = 33;
	char *nome = "Antonio";

	ft_printf("Me chamo %s e tenho %i anos!\n", nome, idade);
	return (0);
}
