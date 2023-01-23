#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNodeHead
{
  struct ListNode *first, **last;
};

#define init_head(r) ((r)->first = 0, (r)->last = &((r)->first))

#define list_push_back(node, head)                                            \
  do                                                                          \
    {                                                                         \
      *((head)->last) = (node);                                               \
      (head)->last = &((node)->next);                                         \
    }                                                                         \
  while (0)

struct ListNode *
mergeTwoLists (struct ListNode *list1, struct ListNode *list2)
{
  struct ListNodeHead head;
  init_head (&head);

  while (list1 && list2)
    {
      if (list1->val <= list2->val)
        {
          list_push_back (list1, &head);
          list1 = list1->next;
        }
      else
        {
          list_push_back (list2, &head);
          list2 = list2->next;
        }
    }

  while (list1)
    {
      list_push_back (list1, &head);
      list1 = list1->next;
    }
  while (list2)
    {
      list_push_back (list2, &head);
      list2 = list2->next;
    }

  return head.first;
}
