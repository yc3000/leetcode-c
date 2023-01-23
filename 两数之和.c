#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
twoSum (int *nums, int numsSize, int target, int *returnSize)
{
  *returnSize = 2;
  int *ret = (int *)malloc (sizeof (int) * 2);

  for (int i = 0; i < numsSize; ++i)
    {
      for (int j = i + 1; j < numsSize; ++j)
        {
          if (nums[i] + nums[j] == target)
            {
              ret[0] = i;
              ret[1] = j;
              break;
            }
        }
    }
  return ret;
}

int
main ()
{
  int nums[3] = { 3, 3 };
  int target = 6;
  int returnSize = 0;

  int *ret = twoSum (nums, 2, target, &returnSize);
  printf ("%d %d", ret[0], ret[1]);
  free (ret);
}
