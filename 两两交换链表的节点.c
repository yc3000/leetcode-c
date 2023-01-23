#include <assert.h>
#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
reverse (struct ListNode *prev, struct ListNode *next)
{
  assert (prev);
  assert (next);

  struct ListNode *new_head = next;
  prev->next = next->next;
  next->next = prev;
  return new_head;
}

struct ListNode *
swapPairs (struct ListNode *head)
{
  struct ListNode myhead;
  myhead.next = NULL;

  struct ListNode *n = &myhead;

  while (1)
    {
      if (head == NULL)
        break;
      if (head->next == NULL)
        {
          n->next = head;
          break;
        }

      struct ListNode *next_head = head->next->next;
      n->next = reverse (head, head->next);
      n = n->next->next;
      head = next_head;
    }

  return myhead.next;
}
