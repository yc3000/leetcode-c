#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct stack
{
  struct TreeNode *vecs[1024];
  int index;
};

void
stack_push (struct stack *head, struct TreeNode *node)
{
  head->vecs[head->index] = node;
  head->index++;
}

struct TreeNode *
stack_pop (struct stack *head)
{
  if (head->index == 0)
    return NULL;

  --head->index;
  return head->vecs[head->index];
}

struct TreeNodeHead
{
  struct TreeNode *first;
  struct TreeNode *last;
};

struct TreeNode *
increasingBST (struct TreeNode *root)
{
  struct TreeNodeHead head;
  head.first = NULL;
  head.last = NULL;

  struct TreeNode *p = root;
  struct stack stack;
  stack.index = 0;

  while (1)
    {
      // 遍历到最左边, 同时收集父节点
      while (p)
        {
          stack_push (&stack, p);
          p = p->left;
        }

      struct TreeNode *node = stack_pop (&stack);
      if (node == NULL)
        break;

      if (head.first == NULL)
        {
          head.first = node;
          head.last = node;
        }
      else
        {
          head.last->right = node;
          head.last = node;
        }

      p = node->right;
    }
  head.last->right = NULL;
  return head.first;
}

int queue[] = { 5, 3, 6, 2, 4, -1, 8, 1, -1, 7, 9 };
int queue_size = sizeof (queue) / sizeof (int);
int queue_index = 0;

// 保证 head 节点不会超过 1024
struct TreeNode *treequeue[1024];
int treequeue_tail = 0;
int treequeue_head = 0;

static inline void
init_treequeue ()
{
  treequeue_tail = treequeue_head = 0;
}

#define treequeue_is_empty (treequeue_tail == treequeue_head)
#define treequeue_push(e) (treequeue[treequeue_head++] = (e))

static inline struct TreeNode *
treequeue_pop ()
{
  ++treequeue_tail;
  return treequeue[treequeue_tail - 1];
}

void
every (struct TreeNode **node, int val)
{
  *node = (struct TreeNode *)malloc (sizeof (struct TreeNode));
  (*node)->left = NULL;
  (*node)->right = NULL;
  (*node)->val = val;
}

// 保证 head 节点不会超过 1024
struct TreeNode **treequeue2[1024];
int treequeue2_tail = 0;
int treequeue2_head = 0;

static inline void
init_treequeue2 ()
{
  treequeue2_tail = treequeue2_head = 0;
}

#define treequeue2_is_empty (treequeue2_tail == treequeue2_head)
#define treequeue2_push(e) (treequeue2[treequeue2_head++] = (e))

static inline struct TreeNode **
treequeue2_pop ()
{
  ++treequeue2_tail;
  return treequeue2[treequeue2_tail - 1];
}

struct TreeNode *
goujian_cengci ()
{
  struct TreeNode *root = NULL;
  init_treequeue2 ();
  treequeue2_push (&root);

  for (int i = 0; i < queue_size; ++i)
    {
      int val = queue[queue_index++];
      struct TreeNode **head = treequeue2_pop ();
      if (val != -1)
        {
          every (head, val);
          treequeue2_push (&((*head)->left));
          treequeue2_push (&((*head)->right));
        }
    }

  return root;
}

void
cengci_bianli (struct TreeNode *root)
{
  init_treequeue ();
  treequeue_push (root);
  struct TreeNode *head;
  printf ("\n---- 不可能 ---------------\n");
  while (!treequeue_is_empty)
    {
      head = treequeue_pop ();
      printf ("%d ", head->val);
      if (head->left)
        treequeue_push (head->left);
      if (head->right)
        treequeue_push (head->right);
    }
}

void
xianxu_bianli (struct TreeNode *root)
{
  if (root == NULL)
    return;
  printf ("%d ", root->val);
  xianxu_bianli (root->left);
  xianxu_bianli (root->right);

  return;
}

void
zhongxu_bianli (struct TreeNode *root)
{
  if (root == NULL)
    return;
  xianxu_bianli (root->left);
  printf ("%d ", root->val);
  xianxu_bianli (root->right);

  return;
}

void
houxu_bianli (struct TreeNode *root)
{
  if (root == NULL)
    return;
  xianxu_bianli (root->left);
  xianxu_bianli (root->right);
  printf ("%d ", root->val);

  return;
}

int
main ()
{
  struct TreeNode *root = NULL;

  root = goujian_cengci ();
  cengci_bianli (root);
  printf (" \n先序遍历\n");
  xianxu_bianli (root);
  printf (" \n中序遍历\n");
  zhongxu_bianli (root);

  /* printf (" \n后序遍历\n"); */
  /* houxu_bianli (root); */

  /* root = increasingBST (root); */
}
