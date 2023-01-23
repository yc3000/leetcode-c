
#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList
{
  struct MyLinkedList *prev;
  struct MyLinkedList *next;
  int val;
} MyLinkedList;

MyLinkedList *
myLinkedListCreate ()
{
  MyLinkedList *l = (MyLinkedList *)malloc (sizeof (MyLinkedList));
  l->prev = l;
  l->next = l;
  return l;
}

int
myLinkedListGet (MyLinkedList *obj, int index)
{
  MyLinkedList *p = obj->next;
  for (int i = 0; i < index && p != obj; ++i)
    p = p->next;

  if (p == obj)
    return -1;

  return p->val;
}

void
myLinkedListAddAtHead (MyLinkedList *obj, int val)
{
  MyLinkedList *node = malloc (sizeof (MyLinkedList));
  node->val = val;
  node->prev = obj;
  node->next = obj->next;
  obj->next->prev = node;
  obj->next = node;
}

void
myLinkedListAddAtTail (MyLinkedList *obj, int val)
{
  MyLinkedList *node = malloc (sizeof (MyLinkedList));
  node->val = val;
  node->prev = obj->prev;
  node->next = obj;

  obj->prev->next = node;
  obj->prev = node;
}

void
myLinkedListAddAtIndex (MyLinkedList *obj, int index, int val)
{
  if (index < 0)
    {
      myLinkedListAddAtHead (obj, val);
      return;
    }

  MyLinkedList *p = obj->next;
  int i;
  for (i = 0; i < index && p != obj; ++i)
    p = p->next;

  if (p == obj)
    {
      if (i == index) /* 尾部插入 */
        {
          myLinkedListAddAtTail (obj, val);
          return;
        }
      else
        return;
    }

  /* 中间插入 */
  myLinkedListAddAtTail (p, val);
}

void
myLinkedListDeleteAtIndex (MyLinkedList *obj, int index)
{
  MyLinkedList *p = obj->next;
  for (int i = 0; i < index && p != obj; ++i)
    p = p->next;

  if (p != obj)
    {
      p->prev->next = p->next;
      p->next->prev = p->prev;
      p->next = NULL;
      p->prev = NULL;
      free (p);
    }
}

void
myLinkedListFree (MyLinkedList *obj)
{
  MyLinkedList *p = obj->next;
  MyLinkedList *next;

  while (p != obj)
    {
      next = p->next;
      free (p);
      p = next;
    }

  free (obj);
}
