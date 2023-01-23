#include <stdio.h>

struct ListNode
{
  struct ListNode *next;
  int val;
};

#define LISTNODE(name) struct ListNode name = { NULL, 0 };

struct ListNode *
rotateRight (struct ListNode *head, int k)
{
  LISTNODE (myhead);

  int size = 0;
  for (struct ListNode *p = head; p; p = p->next, ++size)
    ;

  int move_sz;
  if (size == 0)
    move_sz = 0;
  else if (k < size)
    move_sz = k;
  else
    move_sz = k % size;

  if (move_sz == 0)
    return head;

  struct ListNode *move_head, *move_tail;

  struct ListNode *tmp = head;
  for (int i = 0; i < size - move_sz - 1; ++i)
    tmp = tmp->next;

  move_head = tmp->next;
  tmp->next = NULL;

  for (tmp = move_head; tmp->next; tmp = tmp->next)
    ;
  move_tail = tmp;

  myhead.next = move_head;
  move_tail->next = head;

  return myhead.next;
}
