#include <stdio.h>
#include <stdlib.h>

#define LEN 8

void print_array(int arr[8])
{
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// int cmp(const void *a, const void *b)
// {
//     int arg1 = *(int*)a;
//     int arg2 = *(int*)b;

//     if (arg1 < arg2)
//         return -1;
//     if (arg1 > arg2)
//         return 1;
//     return 0;

//     // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
//     // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
// }

int main()
{
    int values[8] = {3, 2, 1, 4, 8, 0, 0, 0};

    print_array(values);

    qsort(values, 8, sizeof(int), cmp);

    print_array(values);

    return 0;
}