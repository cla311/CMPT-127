#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// list_create copy from t1 - t5
// t1 - t5 implementation are same
list_t *list_create(void)
{
    list_t *l = malloc(sizeof(list_t));
    if (l)
    {
        l->head = NULL;
        l->tail = NULL;
    }
    return l;
}

// list_destroy copy from t1 - t5
// t1 - t5 implementation are same
void list_destroy(list_t *list)
{
  element_t *el = list->head;
  while (el)
  {
    element_t *next = el->next;
    free(el);
    el = next;
  }

  free(list);
}


// element_create implementation is copied from t1,t3,t4,t5
element_t *element_create(int i)
{
    element_t *ele = malloc(sizeof(element_t));
    if (ele == NULL)
    {
        return NULL;
    }
    ele->val = i;
    ele->next = NULL;
    return ele;
}

// list_append implementation copies from t1.c
int list_append(list_t *list, int i)
{
    element_t *ele = element_create(i);
    if (ele == NULL)
    {
        return 1;
    }
    if (list->head == NULL)
    {
        //empty list
        list->head = ele;
        list->tail = ele;
    }
    else
    {
        list->tail->next = ele;
        list->tail = ele;
    }
    return 0;
}

// list_append implementation copies from t1.c
int list_prepend(list_t *list, int i)
{
    element_t *ele = element_create(i);
    if (ele == NULL)
    {
        return 1;
    }
    if (list->head == NULL)
    {
        //empty list
        list->head = ele;
        list->tail = ele;
    }
    else
    {
        ele->next = list->head;
        list->head = ele;
    }

    return 0;
}

element_t *list_index(list_t *list, unsigned int i)
{

    element_t *curr = list->head;
    int count = 0;
    while (curr != NULL)
    {
        if (count == i)
        {
            return curr;
        }
        count++;
        curr = curr->next;
    }
    return NULL;
}

// print does not need to modify
// t1 - t5 implementation are same
void list_print(list_t *list)
{
    printf("{");

    for (element_t *el = list->head;
         el;
         el = el->next)
        printf(" %d", el->val);

    printf(" }\n");
}