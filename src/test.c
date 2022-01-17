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

int counter;
void count(void *x)
{
    counter += *(int *)x;
}

void set_4(void *x)
{
    *(int *)x = 4;
}

int buffer[12];
size_t i = 0;
void write_sum(void *x, void *y)
{
    buffer[i++] = *(int *)x + *(char *)y;
}

int main()
{
    int a[] = {1, 4, 3, 2, 1, 4};
    ASSERT(find_first(a, 6, sizeof(int), is_4) == a + 1);
    ASSERT(find_first(a, 6, sizeof(int), is_greater_than_10) == NULL);

    int c[] = {4, 4, 4, 4, 4, 4};
    ASSERT(!all(a, 6, sizeof(int), is_4));
    ASSERT(all(c, 6, sizeof(int), is_4));

    int d[] = {1, 2, 3, 4, 5};
    counter = 0;
    foreach(d, 5, sizeof(int), count);
    ASSERT(counter == 15);
    foreach(d, 5, sizeof(int), set_4);
    ASSERT(all(d, 5, sizeof(int), is_4));

    int e1[] = {0, 1, 2};
    char e2[] = {6, 5, 3, 2};
    cartesian_foreach(e1, 3, sizeof(int), e2, 4, sizeof(char), write_sum);
    ASSERT(find_first(buffer, 12, sizeof(int), is_4) == buffer + 6);
}
