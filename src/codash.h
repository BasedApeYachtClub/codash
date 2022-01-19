#include <stdbool.h>
#include <stddef.h>

void *find_first(void *xs, size_t len, size_t size, bool (*predicate)(void *));
//void *find_nth(void *xs, size_t len, size_t size, bool (*predicate)(void *), size_t n);
//size_t count(void *xs, size_t len, size_t size, bool (*predicate)(void *));

bool all(void *xs, size_t len, size_t size, bool (*predicate)(void *));


bool any(void *xs, size_t len, size_t size, bool (*predicate)(void *));

bool none(void *xs, size_t len, size_t size, bool (*predicate)(void *));

/**
 * @brief Perform an action for every element of an array
 *
 * Iterates over `xs`.
 * For each element, calls `action` with a pointer to that element.
 * Note that this gives `action` writing access to the elements of `xs`.
 * `foreach` can therefore be used to modify the array.
 * This is generally advised against as the corresponding {@link cartesian_foreach} is not suitable to modify its arrays.
 *
 * Runtime: O(len)
 *
 * @param xs The array
 * @param len Number of elements `xs` has
 * @param size Size of each element in `xs`
 * @param action The action to perform on each element
 */
void foreach(void *xs, size_t len, size_t size, void (*action)(void *x));

/**
 * @brief Perform an action for every combination of elements of two given arrays
 *
 * Iterates over `xs` and `ys`.
 * For each combination of elements, calls `action` with pointers to said elements.
 * `cartesian_foreach` will first iterate over `ys`. So the call order will be
 * ```
 * action(x0, y0);
 * action(x0, y1);
 * action(x0, y2);
 * action(x1, y0);
 * ...
 *```
 *
 * Note that this gives `action` writing access to the elements of `xs` and `ys`.
 * As `action` is called a variable number times on the same array element (`action` is called `len_ys` times on `x0`),
 * it is advised against using it to modify the arrays.
 *
 * @param xs The first array
 * @param len_xs Number of elements `xs` has
 * @param size_x Size of each element in `xs`
 * @param ys The second array
 * @param len_ys Number of elements `ys` has
 * @param size_y Size of each element in `ys`
 * @param action The action to perform on each element
 */
void cartesian_foreach(void *xs, size_t len_xs, size_t size_x, void *ys, size_t len_ys, size_t size_y, void (*action)(void *x, void *y));


// TODO len is not number of bytes docs
//void map(void *dst, void *src, size_t dst_size, size_t src_size, size_t len, void (*f)(void *d, void *s));
//void filter(void *dst, void *src, size_t len, size_t size, bool (*predicate)(void *));
// calls filter
//void filter_inplace(void *xs, size_t len, size_t size, bool (*predicate)(void *));
//void reduce(void *start, void *xs, size_t len, size_t size, void (*reducer)(void *acc, void *x));
// reduce_right
// flatmap
// forever
// shuffle
// sample_n (with or without duplicates)
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
