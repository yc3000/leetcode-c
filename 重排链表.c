#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
reverse (struct ListNode *head)
{
  struct ListNode *newhead = 0;

  while (head)
    {
      struct ListNode *tmp = head;
      head = head->next;
      tmp->next = newhead;
      newhead = tmp;
    }

  int lst_sz = 0;
  for (struct ListNode *p = newhead; p; p = p->next)
    {
      lst_sz++;
    }

  struct ListNode *p = newhead;
  for (int i = 0; i < lst_sz / 2 - 1; ++i)
    {
      p = p->next;
    }
  p->next = NULL;

  return newhead;
}

void
reorderList (struct ListNode *head)
{
  struct ListNode *newhead = NULL;
  struct ListNode **newhead_last = &newhead;

  for (struct ListNode *p = head; p; p = p->next)
    {
      *newhead_last = malloc (sizeof (struct ListNode));
      (*newhead_last)->val = p->val;
      (*newhead_last)->next = p->next;
      newhead_last = &((*newhead_last)->next);
    }

  struct ListNode *rhead = reverse (newhead);
  struct ListNode *head_next, *rhead_next;

  if (!head || !head->next)
    {
      return;
    }

  int flag = 0; // 判断左右链表
  struct ListNode **next = &(head->next);
  head = head->next;

  while (rhead)
    {
      if (flag == 0)
        {
          *next = rhead;
          next = &(rhead->next);
          rhead = rhead->next;
          flag = 1;
        }
      else
        {
          *next = head;
          next = &(head->next);
          head = head->next;
          flag = 0;
        }
    }
}

/* ==============================================
 * 测试用例
 * ============================================= */
int
main ()
{
  struct ListNode *head;
  struct ListNode **last = &head;
  for (int i = 0; i < 4; ++i)
    {
      *last = malloc (sizeof (struct ListNode));
      (*last)->val = i + 1;
      (*last)->next = NULL;
      last = &((*last)->next);
    }

  reorderList (head);
  while (head)
    {
      printf ("%d ", head->val);
      head = head->next;
    }
}
