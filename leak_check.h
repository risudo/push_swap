#ifndef LEAK_CHECK_H
# define LEAK_CHECK_H
#include <stdlib.h>
#include <stdio.h>

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);

#endif