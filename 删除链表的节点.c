#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
deleteNode (struct ListNode *head, int val)
{
  struct ListNode *prev, *entry;
  prev = NULL;
  entry = head;

  while (entry)
    {
      if (entry->val == val)
        if (prev == NULL)
          {
            head = head->next;
            break;
          }
        else
          {
            prev->next = entry->next;
          }

      prev = entry;
      entry = entry->next;
    }

  return head;
}
