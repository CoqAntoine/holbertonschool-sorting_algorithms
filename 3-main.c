#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

void test_array(int *array, size_t size, const char *desc)
{
    printf("=== Test: %s (size=%lu) ===\n", desc, size);
    printf("Avant tri : ");
    print_array(array, size);
    quick_sort(array, size);
    printf("Apres tri: ");
    print_array(array, size);
    printf("\n");
}


int *generate_random_array(size_t size, int min, int max)
{
    size_t i;
    int *arr;
    arr = malloc(size * sizeof(int));
    if (size == 0) return NULL;
    if (!arr) return NULL;
    for (i = 0; i < size; i++)
        arr[i] = (rand() % (max - min + 1)) + min;
    return arr;
}


int *generate_sorted_array(size_t size)
{
    size_t i;
    int *arr;
    arr = malloc(size * sizeof(int));
    if (!arr) return NULL;
    for (i = 0; i < size; i++)
        arr[i] = (int)i;
    return arr;
}

int *generate_reverse_sorted_array(size_t size)
{
    size_t i;
    int *arr;
    arr = malloc(size * sizeof(int));
    if (!arr) return NULL;
    for (i = 0; i < size; i++)
        arr[i] = (int)(size - i);
    return arr;
}

int main(void)
{
    int empty[1];
    int one[1] = {42};
    int equals[5] = {7, 7, 7, 7, 7};
    int sorted[7] = {1, 2, 3, 4, 5, 6, 7};
    int reversed[7] = {7, 6, 5, 4, 3, 2, 1};
    int duplicates[8] = {3, 5, 3, 2, 8, 5, 1, 3};
    int negpos[7] = {-5, 3, 0, -2, 9, -8, 4};
    int two_elems[2] = {2, 1};
    int extremes[5] = {2147483647, -2147483648, 0, 123456, -123456};
   /** int *big_random;
    size_t big_size = 100;**/

    srand((unsigned int)time(NULL));

    test_array(empty, 0, "Tableau vide");
    test_array(one, 1, "Un element");
    test_array(equals, 5, "Tous egaux");
    test_array(sorted, 7, "Deja trie:");
    test_array(reversed, 7, "Tri decroissant");
    test_array(duplicates, 8, "Doublons");
    test_array(negpos, 7, "Negatifs et positifs");

/**    big_random = generate_random_array(big_size, -1000, 1000);
    if (big_random != NULL)
    {
        test_array(big_random, big_size, "Grand tableau aleatoire");
        free(big_random);
    }
**/
    test_array(two_elems, 2, "Deux elements");
    test_array(extremes, 5, "Valeurs extremes");

    return 0;
}
