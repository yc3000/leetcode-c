#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

static inline void
swap (struct ListNode **head, struct ListNode *prev, struct ListNode *lhs,
      struct ListNode *rhs)
{
  // prev lhs rhs next
  struct ListNode *next = rhs->next;

  if (prev)
    prev->next = rhs;
  else
    *head = rhs;

  rhs->next = lhs;
  lhs->next = next;
}

struct ListNode *
sortList (struct ListNode *head)
{
  if (!head || head->next == NULL)
    return NULL;

  struct ListNode *end = NULL;
  struct ListNode *end_prev = NULL;
  struct ListNode *curr = head;
  struct ListNode *prev = NULL;
  struct ListNode *save_curr;
  // 2 1 3 5 1

  while (curr->next != end)
    {
      prev = NULL;
      save_curr = curr->next;
      while (curr->next != end)
        {
          if (curr->val > curr->next->val)
            {
              swap (&head, prev, curr, curr->next);
            }
          prev = curr;
          curr = curr->next;
          if (curr->next == end)
            {
              end_prev = curr;
            }
        }
      end = end_prev;
      curr = save_curr;
    }
  return head;
}

int
main ()
{
}
