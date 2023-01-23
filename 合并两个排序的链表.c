#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

#define fuckyou(l)                                                            \
  do                                                                          \
    {                                                                         \
      *last = l;                                                              \
      last = &(l->next);                                                      \
      l = l->next;                                                            \
    }                                                                         \
  while (0)

struct ListNode *
mergeTwoLists (struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode head;
  head.val = 0;
  head.next = NULL;
  struct ListNode **last = &(head.next);

  while (l1 && l2)
    {
      if (l1->val < l2->val)
        fuckyou (l1);
      else
        fuckyou (l2);
    }

  if (l1)
    fuckyou (l1);
  else if (l2)
    fuckyou (l2);

  return head.next;
}
