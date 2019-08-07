#include <stdio.h>
#include "intarr.c"

int main()
{
    // intarr_t *ptr1 = intarr_create(5);
    // intarr_set(ptr1, 0, 0); // 0
    // intarr_set(ptr1, 1, 1); // 1
    // intarr_set(ptr1, 2, 2); // 2
    // intarr_set(ptr1, 3, 3); // 3
    // intarr_set(ptr1, 4, 4); // 4
    // intarr_t *new_ptr1 = intarr_copy(ptr1);

    // task 1
    // const char filename[8] = "file.txt";
    // int result = intarr_save_binary(new_ptr1, filename);
    // if (result == 0)
    // {
    //     intarr_t *ptr = intarr_load_binary(filename);

    //     for (int i = 0; i < ptr->len; i++)
    //     {
    //         printf("%d\n", ptr->data[i]);
    //     }
    // }

    // task 2
    // const char filename[8] = "arr.json";
    // int result = intarr_save_json(new_ptr1, filename);

    // if (result == 0)
    // {
    //     intarr_t *ptr = intarr_load_json(filename);
    //         for (int i = 0; i < ptr->len; i++)
    //         {
    //             printf("%d\n", ptr->data[i]);
    //         }
    // }
    return 0;
}
