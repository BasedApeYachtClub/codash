#include <stdbool.h>
#include <stdlib.h>

#define FOR_INDEX(I, N) for (size_t(I) = 0; (I) < (N); ++(I))

void *find_first(void *xs, size_t len, size_t size, bool (*predicate)(void *))
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

bool all(void *xs, size_t len, size_t size, bool (*predicate)(void *))
{
    if (len == 0)
    {
        return true;
    }
    else
    {
        return predicate(xs) && all(xs + size, len - 1, size, predicate);
    }
}

bool any(void *xs, size_t len, size_t size, bool (*predicate)(void *))
{

    if (len == 0)
    {
        return false;
    }
    else
    {
        return predicate(xs) || any(xs + size, len - 1, size, predicate);
    }
}

bool none(void *xs, size_t len, size_t size, bool (*predicate)(void *))
{
    return !any(xs, len, size, predicate);
}
