#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNodeHead
{
  struct ListNode *first, **last;
};

struct ListNode *
reverseList (struct ListNode *head)
{
  struct ListNodeHead myhead;
  myhead.first = NULL;
  myhead.last = NULL;

  while (head)
    {
      struct ListNode *tmp = head;
      head = head->next;
      tmp->next = myhead.first;
      myhead.first = tmp;
    }

  return myhead.first;
}
