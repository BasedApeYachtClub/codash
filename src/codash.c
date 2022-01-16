#include <stdlib.h>

#define FOR_INDEX(I, N) for (size_t(I) = 0; (I) < (N); ++(I))

void *find_first(void *xs, size_t len, size_t size, int (*predicate)(void *))
{
    FOR_INDEX(i, len)
    {
        if (predicate(xs + i * size))
        {
            return xs + i * size;
        }
    }
    return NULL;
}
