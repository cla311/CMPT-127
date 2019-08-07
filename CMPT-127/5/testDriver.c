#include <stdio.h>
#include "intarr.c"

int main()
{
    //task 1
    // printf("Task 1\n");
    intarr_t *ptr1 = intarr_create(5);
    // printf("%d\n", ptr1->len);
    // intarr_t *ptr2 = intarr_create(100);
    // printf("%d\n", ptr2->len);
    // intarr_t *ptr3 = intarr_create(1000);
    // printf("%d\n", ptr3->len);

    //task 2
    // printf("Task 2\n");
    intarr_set(ptr1, 0, 5);
    printf("%d\n", ptr1->data[0]);
    int val = 2;
    intarr_get(ptr1, 1, &val);
    // printf("%d\n", val);

    // task 3
    printf("Task 3\n");
    intarr_set(ptr1, 1, 4);
    intarr_set(ptr1, 2, 3);
    intarr_set(ptr1, 3, 2);
    intarr_set(ptr1, 4, 1);
    intarr_t *new_ptr1 = intarr_copy(ptr1);
    printf("%d\n", new_ptr1->len);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", new_ptr1->data[i]);
    }
    printf("\n");

    // task 4
    intarr_sort(new_ptr1);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", new_ptr1->data[i]);
    }
    printf("\n");

    //task 6
    // intarr_result_t result1 = intarr_push(new_ptr1, 100);
    // printf("Task6\n");
    // int val = 0;

    // intarr_result_t result2 = intarr_pop(new_ptr1, &val);
    // result == 0 means ok otherwise not okey

    // for (int i = 0; i < new_ptr1->len; i++)
    // {
    //     printf("%d\n", new_ptr1->data[i]);
    // }

    // printf("Value: %d\n",val);

    // task 7
    // printf("Task7\n");
    // intarr_resize(new_ptr1, 5);
    // for (int i = 0; i < new_ptr1->len; i++)
    // {
    //     printf("%d\n", new_ptr1->data[i]);
    // }

    // task 8
    // 0 1 2
    // 10 9 8
    // printf("\n");
    // printf("Task8\n");
    // intarr_t *copy_ptr = intarr_copy_subarray(new_ptr1, 2, 4);
    // for (int i = 0; i < copy_ptr->len; i++)
    // {
    //     printf("%d\n", copy_ptr->data[i]);
    // }
}