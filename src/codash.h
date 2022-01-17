#include <stdbool.h>
#include <stddef.h>

void *find_first(void *xs, size_t len, size_t size, bool (*predicate)(void *));
//void *find_nth(void *xs, size_t len, size_t size, bool (*predicate)(void *), size_t n);
//size_t count(void *xs, size_t len, size_t size, bool (*predicate)(void *));

bool all(void *xs, size_t len, size_t size, bool (*predicate)(void *));

bool any(void *xs, size_t len, size_t size, bool (*predicate)(void *));

bool none(void *xs, size_t len, size_t size, bool (*predicate)(void *));

// TODO len is not number of bytes docs
//void map(void *dst, void *src, size_t dst_size, size_t src_size, size_t len, void (*f)(void *d, void *s));
//void filter(void *dst, void *src, size_t len, size_t size, bool (*predicate)(void *));
// calls filter
//void filter_inplace(void *xs, size_t len, size_t size, bool (*predicate)(void *));
//void reduce(void *start, void *xs, size_t len, size_t size, void (*reducer)(void *acc, void *x));
// reduce_right
// flatmap
// foreach
// forever
// shuffle
// sample_n (with or without duplicates)
// (cartesian foreach funccalls)
// find_last
// numpy level slicing to new array
// fill (constant value, not byte)
// TODO new name: fill_with_array (iterates through elements, allows dynamic array size to fill, sth sth modulo length)
// reverse
// reverse inplace (warning: this is terribly slow) (either single byte copy (char on stack) or XOR swap algo)
// itertools.accumulate like
// many sort algorithms
// also some fun algorithms as well (think Rabin Karp)

// unique
// group
// cluster
// (Difference group/cluster: groups uses equivalence relations (A->A->bool) while cluster uses (A->Int)
// (and every valid int is a bucket))

// zip
// zip3

// TODO lodash
