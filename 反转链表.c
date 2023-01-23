#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
reverseList (struct ListNode *head)
{
  struct ListNode *new_head = NULL;
  while (head)
    {
      struct ListNode *tmp = head;
      head = head->next;
      tmp->next = new_head;
      new_head = tmp;
    }
  return new_head;
}
