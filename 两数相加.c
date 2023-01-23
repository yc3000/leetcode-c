/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
addTwoNumbers (struct ListNode *l1, struct ListNode *l2)
{
  int next_val = 0;
  struct ListNode *head, *p;
  head = p = NULL;

  int l1val, l2val;
  while (l1 != NULL || l2 != NULL)
    {
      if (l1 == NULL)
        l1val = 0;
      else
        l1val = l1->val;

      if (l2 == NULL)
        l2val = 0;
      else
        l2val = l2->val;

      int val = l1val + l2val + next_val;

      if (val >= 10)
        {
          val = val % 10;
          next_val = 1;
        }
      else
        next_val = 0;

      struct ListNode *tmp
          = (struct ListNode *)malloc (sizeof (struct ListNode));
      tmp->val = val;
      tmp->next = NULL;

      if (head == NULL)
        {
          head = tmp;
          p = head;
        }
      else
        {
          p->next = tmp;
          p = p->next;
        }

      if (l1 != NULL)
        l1 = l1->next;
      if (l2 != NULL)
        l2 = l2->next;
    }

  if (next_val == 1)
    {
      p->next = malloc (sizeof (struct ListNode));
      p->next->val = 1;
      p->next->next = NULL;
    }

  return head;
}

int
main ()
{
}
