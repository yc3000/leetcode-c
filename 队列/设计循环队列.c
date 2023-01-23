#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ringbuf
{
  char *data;
  long size;
  long head;
  long tail;
};

#define ringbuf_used_size(c)                                                  \
  (((c)->head >= (c)->tail) ? ((c)->head - (c)->tail)                         \
                            : (((c)->size - (c)->tail) + (c)->head))

#define ringbuf_free_size(r) ((r)->size - ringbuf_used_size (r) - 1)

void
ringbuf_init (struct ringbuf *r, void *buf, long size)
{
  r->data = (char *)buf;
  r->size = size;
  r->head = 0;
  r->tail = 0;
}

long
ringbuf_write (struct ringbuf *r, const void *buf, long size)
{
  long used_sz, free_sz, half;
  char *lptr;

  lptr = (char *)buf;
  used_sz = ringbuf_used_size (r);
  free_sz = ringbuf_free_size (r);

  if (free_sz <= 0)
    return 0;

  size = (size > free_sz) ? free_sz : size;
  half = r->size - r->head;

  if (lptr)
    {
      if (half >= size)
        {
          memcpy (r->data + r->head, lptr, (size_t)size);
        }
      else
        {
          memcpy (r->data + r->head, lptr, (size_t)half);
          memcpy (r->data, lptr + half, (size_t)(size - half));
        }
    }

  r->head += size;
  if (r->head >= r->size)
    r->head -= r->size;

  return size;
}

long
ringbuf_peek (struct ringbuf *r, void *buf, long size)
{
  long used_sz, free_sz, half;
  char *lptr;

  lptr = (char *)buf;
  used_sz = ringbuf_used_size (r);
  free_sz = ringbuf_free_size (r);

  if (used_sz <= 0)
    return 0;

  size = (used_sz < size) ? used_sz : size;
  half = r->size - r->tail;

  if (half >= size)
    {
      memcpy (lptr, r->data + r->tail, (size_t)size);
    }
  else
    {
      memcpy (lptr, r->data + r->tail, (size_t)half);
      memcpy (lptr + half, r->data, (size_t)(size - half));
    }

  return size;
}

long
ringbuf_read (struct ringbuf *r, void *buf, long size)
{
  long nsize;

  nsize = ringbuf_peek (r, buf, size);
  if (nsize <= 0)
    return 0;

  r->tail += size;
  if (r->tail >= r->size)
    r->tail -= r->size;

  return nsize;
}

typedef struct
{
  struct ringbuf rb;
  int *data;
} MyCircularQueue;

MyCircularQueue *
myCircularQueueCreate (int k)
{
  k = k + 1;
  MyCircularQueue *q = malloc (sizeof (MyCircularQueue));
  q->data = malloc (sizeof (int) * k);
  ringbuf_init (&q->rb, q->data, sizeof (int) * k);
  return q;
}

extern bool myCircularQueueIsEmpty (MyCircularQueue *obj);
extern bool myCircularQueueIsFull (MyCircularQueue *obj);

bool
myCircularQueueEnQueue (MyCircularQueue *obj, int value)
{
  long sz = ringbuf_write (&obj->rb, &value, sizeof (int));
  if (sz <= 0)
    return false;
  return true;
}

bool
myCircularQueueDeQueue (MyCircularQueue *obj)
{
  int ret;
  long sz = ringbuf_read (&obj->rb, &ret, sizeof (int));
  if (sz <= 0)
    return false;
  return true;
}

int
myCircularQueueFront (MyCircularQueue *obj)
{
  /* PEEK */
  int ret;
  long sz = ringbuf_peek (&obj->rb, &ret, sizeof (int));
  if (sz <= 0)
    return -1;
  return ret;
}

int
myCircularQueueRear (MyCircularQueue *obj)
{
  if (myCircularQueueIsEmpty (obj))
    return -1;

  char *ptr;
  int ret;

  if (obj->rb.head <= 0)
    ptr = obj->rb.data + obj->rb.size - sizeof (int);
  else
    ptr = obj->rb.data + obj->rb.head - sizeof (int); // 0.head tail

  memcpy (&ret, ptr, sizeof (int));
  return ret;
}

bool
myCircularQueueIsEmpty (MyCircularQueue *obj)
{
  long used_sz = ringbuf_used_size (&obj->rb);
  return used_sz == 0;
}

bool
myCircularQueueIsFull (MyCircularQueue *obj)
{
  long free_sz = ringbuf_free_size (&obj->rb);
  return free_sz == 0;
}

void
myCircularQueueFree (MyCircularQueue *obj)
{
  free (obj->data);
  free (obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

int
main ()
{
  bool bo;
  MyCircularQueue *obj = myCircularQueueCreate (3);

  bo = myCircularQueueEnQueue (obj, 3);
  assert (bo);
  bo = myCircularQueueEnQueue (obj, 2);
  assert (bo);
  bo = myCircularQueueEnQueue (obj, 1);
  assert (bo);

  bo = myCircularQueueDeQueue (obj);
  assert (bo);

  int front = myCircularQueueFront (obj);
  int rear = myCircularQueueRear (obj);

  printf ("%d %d", front, rear);
}
