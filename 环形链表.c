#include <stdbool.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

bool
hasCycle (struct ListNode *head)
{
  while (head)
    {
      if (head->val == 10001)
        return true;

      head->val = 10001;
      head = head->next;
    }
  return false;
}
