#include <stdbool.h>

#include <stdlib.h>
#include <uthash.h>

struct hash_item
{
  int key;
  int val;
  UT_hash_handle hh;
};

void
hash_find (struct hash_item *item, int val, )
{
}

void
hash_insert (struct hash_item *item, int key, int val)
{
  struct hash_item *add = malloc (sizeof (struct hash_item));
  add->key = key;
  add->val = val;

  HASH_ADD_INT (item, key, add);
}

typedef struct
{
  int *nums;
  int nums_sz;

  struct hash_item hashtable;
} RandomizedSet;

/** Initialize your data structure here. */

RandomizedSet *
randomizedSetCreate ()
{
}

/** Inserts a value to the set. Returns true if the set did not already contain
 * the specified element. */
bool
randomizedSetInsert (RandomizedSet *obj, int val)
{
}

/** Removes a value from the set. Returns true if the set contained the
 * specified element. */
bool
randomizedSetRemove (RandomizedSet *obj, int val)
{
}

/** Get a random element from the set. */
int
randomizedSetGetRandom (RandomizedSet *obj)
{
}

void
randomizedSetFree (RandomizedSet *obj)
{
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/

#define MAX_NUM_SIZE 10001

typedef struct
{
  int key;
  int val;
  UT_hash_handle hh;
} HashItem;

bool
findHash (const HashItem **obj, int key)
{
  HashItem *pEntry = NULL;
  HASH_FIND_INT (*obj, &key, pEntry);
  if (NULL != pEntry)
    {
      return true;
    }
  return false;
}

int
getHash (const HashItem **obj, int key)
{
  HashItem *pEntry = NULL;
  HASH_FIND_INT (*obj, &key, pEntry);
  if (NULL == pEntry)
    {
      return -1;
    }
  return pEntry->val;
}

void
insertHash (HashItem **obj, int key, int val)
{
  HashItem *pEntry = NULL;
  HASH_FIND_INT (*obj, &key, pEntry);
  if (NULL != pEntry)
    {
      pEntry->val = val;
    }
  else
    {
      pEntry = (HashItem *)malloc (sizeof (HashItem));
      pEntry->key = key;
      pEntry->val = val;
      HASH_ADD_INT (*obj, key, pEntry);
    }
}

bool
removeHash (HashItem **obj, int key)
{
  HashItem *pEntry = NULL;
  HASH_FIND_INT (*obj, &key, pEntry);
  if (NULL != pEntry)
    {
      HASH_DEL (*obj, pEntry);
      free (pEntry);
    }
  return true;
}

void
freeHash (HashItem **obj)
{
  HashItem *curr, *tmp;
  HASH_ITER (hh, *obj, curr, tmp)
  {
    HASH_DEL (*obj, curr);
    free (curr);
  }
}

typedef struct
{
  int *nums;
  int numsSize;
  HashItem *indices;
} RandomizedSet;

RandomizedSet *
randomizedSetCreate ()
{
  srand ((unsigned)time (NULL));
  RandomizedSet *obj = (RandomizedSet *)malloc (sizeof (RandomizedSet));
  obj->nums = (int *)malloc (sizeof (int) * MAX_NUM_SIZE);
  obj->numsSize = 0;
  obj->indices = NULL;
  return obj;
}

bool
randomizedSetInsert (RandomizedSet *obj, int val)
{
  HashItem *pEntry = NULL;
  if (findHash (&obj->indices, val))
    {
      return false;
    }
  int index = obj->numsSize;
  obj->nums[obj->numsSize++] = val;
  insertHash (&obj->indices, val, obj->numsSize - 1);
  return true;
}

bool
randomizedSetRemove (RandomizedSet *obj, int val)
{
  if (!findHash (&obj->indices, val))
    {
      return false;
    }
  int index = getHash (&obj->indices, val);
  int last = obj->nums[obj->numsSize - 1];
  obj->nums[index] = last;
  insertHash (&obj->indices, last, index);
  obj->numsSize--;
  removeHash (&obj->indices, val);
  return true;
}

int
randomizedSetGetRandom (RandomizedSet *obj)
{
  int randomIndex = rand () % obj->numsSize;
  return obj->nums[randomIndex];
}

void
randomizedSetFree (RandomizedSet *obj)
{
  freeHash (&obj->indices);
  free (obj->nums);
  free (obj);
}
