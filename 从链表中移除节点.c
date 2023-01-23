#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNodeHead
{
  struct ListNode *first;
  struct ListNode **last;
};

struct ListNode *
removeNodes (struct ListNode *head)
{
  struct ListNodeHead myhead;

  struct ListNode *curr = head;
  struct ListNode *del = head;
  int prev_val = 100001;

  while (curr)
    {
      if (curr->val > prev_val)
        {
        }
    }

  return myhead.first;
}
