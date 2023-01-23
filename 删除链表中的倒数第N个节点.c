/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
reverse (struct ListNode *head)
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

struct ListNode *
removeNthFromEnd (struct ListNode *head, int n)
{
  head = reverse (head);
  struct ListNode *p = head;

  if (n == 1)
    head = head->next;
  else
    {
      for (int i = 1; i < n - 1; ++i)
        p = p->next;
      p->next = p->next->next;
    }

  head = reverse (head);
  return head;
}
