#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

int main(int argc, char *argv[])
{
  // test the create function
  list_t *list = list_create();

  // check to see if the create function did everything it was supposed to
  if (list == NULL)
  {
    printf("create: create failed to malloc\n");
    return 1;
  }

  if (list->head != NULL)
  {
    printf("create: head is not null!\n");
    return 1;
  }

  if (list->tail != NULL)
  {
    printf("create: tail is not null!\n");
    return 1;
  }

  ////////////////////////////////////
  ////////////////////////////////////
  ////////////////////////////////////
  ////////////////////////////////////
  //  my implementation starts from here
  //  test the list_index function
  list_append(list, 0);
  list_append(list, 10);
  list_append(list, 20);
  list_append(list, 30);
  list_append(list, 40);
  element_t *el15 = list_index(list, 20);
  if (el15 != NULL)
  {
    printf("index is out of scope\n");
    return 1;
  }
  // test for empty list
  list_t *list1 = list_create();
  element_t *el1 = list_index(list1, 20);
  if (el1 != NULL)
  {
    printf("t1 failed.\n");
    return 1;
  }

  //  test the element_create function
  //  t2.c has an error, element_create doesn't set el->next to NULL
  list_t *list2 = list_create();
  element_t *test = element_create(10);
  element_t *test2 = element_create(20);
  test2->next = test;
  free(test2);
  list_append(list2, 10);
  if (list2->tail->next != NULL)
  {
    printf("t2 failed.\n");
    return 1;
    assert(list->tail->next == NULL);
  }

  //  test the list_index function
  //  t3.c has an error, element_index doesnt check if list is empty
  list_t *list3 = list_create();
  for (int i = 0; i < 5; i++)
  {
    list_append(list3, i);
  }
  //  list3 : 0, 1, 2, 3, 4
  //  el3 is supposed to point at index 0
  element_t *el3 = list_index(list3, 0);
  if (el3->val != 0)
  {
    printf("t3 failed.\n");
    return 1;
  }

  //  test the list_prepend function
  //  t4.c has an error, list prepend doesnt check if list is empty to set tail to new element
  list_t *list4 = list_create();
  list_prepend(list4, 100);
  if (list4->tail != list4->head)
  {
    printf("t4 failed.\n");
    return 1;
  }

  return 0;
}
