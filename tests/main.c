#include "test.h"

int	main(void)
{


	int idade = 33;
	char *nome = "Antonio";

	ft_printf("Test s e i: Me chamo %s e tenho %i anos!\n", nome, idade);
	ft_printf("Test s: Valor2: %s\n", "teste");

	ft_printf("Test d e %: Valor com %d%% de desconto\n", 10);
	ft_printf("Test d: Valor: %d\n", 42);

	ft_printf("Test x: %x\n", 42);

	ft_printf("Test X: %X\n", 42);

	ft_printf("Test p: %p\n", &idade);
	return (0);
}
