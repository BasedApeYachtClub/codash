#include "codash.h"

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(CONDITION)                                                                   \
    if ((CONDITION) == false)                                                               \
    {                                                                                       \
        fprintf(stderr, "ASSERT: Condition in line %d failed: %s\n", __LINE__, #CONDITION); \
        exit(1);                                                                            \
    }

bool is_4(void *x)
{
    return *(int *)x == 4;
}

bool is_greater_than_10(void *x) {
    return *(int *)x > 10;
}

int main()
{
    int a[] = {1, 4, 3, 2, 1, 4};
    ASSERT(find_first(a, 6, sizeof(int), is_4) == a + 1);
    ASSERT(find_first(a, 6, sizeof(int), is_greater_than_10) == NULL);

    int c[] = {4, 4, 4, 4, 4, 4};
    ASSERT(!all(a, 6, sizeof(int), is_4));
    ASSERT(all(c, 6, sizeof(int), is_4));

    ASSERT(!any(a, 6, sizeof(int), is_greater_than_10));
    ASSERT(any(a, 6, sizeof(int), is_4));

    ASSERT(none(a, 6, sizeof(int), is_greater_than_10));
    ASSERT(!none(a, 6, sizeof(int), is_4));
}
