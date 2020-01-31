
#include "../../includes/libft.h"

void    ft_swap(void *a, void *b, size_t size)
{

    void    *tmp;

    tmp = ft_memalloc(size);
    ft_memmove(tmp, a, size);
    ft_memmove(a, b, size);
    ft_memmove(b, tmp, size);
    ft_memdel(&tmp);
}