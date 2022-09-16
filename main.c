#include "./src/ft_printf.h"

int	main(void)
{
	ft_printf("Valor: %d\n", 42);
	ft_printf("Valor2: %s\n", "teste");
	int idade = 29;
	char *nome = "Rods";

	ft_printf("Me chamo %s e tenho %i anos!\n", nome, idade);
	return (0);
}
