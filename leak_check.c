#include "leak_check.h"

void	*ft_malloc(size_t size)
{
	static int cnt;

	if (cnt == 3)
		return (NULL);
	cnt++;
	printf("malloc cnt: %d\n", cnt);
	return (malloc(size));
}

void	ft_free(void *ptr)
{
	static int	cnt;

	cnt++;
	printf("free cnt: %d\n", cnt);
	free(ptr);
}