#include <stdlib.h>

#define FOR_INDEX(I, N) for (size_t(I) = 0; (I) < (N); ++(I))

void *find_first(void *xs, size_t xs_len, size_t x_size, int (*predicate)(void *))
{
    FOR_INDEX(i, xs_len)
    {
        if (predicate(xs + i * x_size))
        {
            return xs + i * x_size;
        }
    }
    return NULL;
}