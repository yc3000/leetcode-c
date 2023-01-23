#include <stdbool.h>
#include <stdio.h>

struct list_head
{
  struct list_head *prev, *next;
};

#define init_list_head(lst) ((lst)->prev = (lst), (lst)->next = (lst))

static inline void
__list_add (struct list_head *node, struct list_head *prev,
            struct list_head *next)
{
  node->prev = prev;
  node->next = next;
  node->prev->next = node;
  node->next->prev = node;
}

static inline void
list_add_tail (struct list_head *node, struct list_head *head)
{
  __list_add (node, head->prev, head);
}

static inline void
__list_del (struct list_head *prev, struct list_head *next)
{
  prev->next = next;
  next->prev = prev;
}

static inline void
list_del_init (struct list_head *entry)
{
  __list_del (entry->prev, entry->next);
  init_list_head (entry);
}

struct head_node
{
  struct heap_node *parent, *left, *right;
};

typedef int (*heap_compare_fn) (const struct head_node *lhs,
                                const struct head_node *rhs);
struct heap
{
  struct head_node *root;
  int nelts;
  heap_compare_fn compare;
};

struct entry
{
  struct list_head head;
  struct heap heap;
  bool is_move;
};

void
heap_init (struct heap *heap, heap_compare_fn fn)
{
  heap->root = NULL;
  heap->nelts = 0;
  heap->compare = fn;
}

void
heap_insert (struct heap *heap, struct heap_node *node)
{ /*  */
  int path = 0;
  int n, d;

  ++heap->nelts;

  for (d = 0; n = heap->nelts; n >= 2; ++d, n >>= 1)
    {
    }
}

void
heap_remove (struct heap *heap, struct heap_node *node)
{ /*  */
}

/*  */

/*  */

/*  */

/*  */

/*  */
typedef struct
{
} MaxQueue;

MaxQueue *
maxQueueCreate ()
{
}

int
maxQueueMax_value (MaxQueue *obj)
{
}

void
maxQueuePush_back (MaxQueue *obj, int value)
{
}

int
maxQueuePop_front (MaxQueue *obj)
{
}

void
maxQueueFree (MaxQueue *obj)
{
}
