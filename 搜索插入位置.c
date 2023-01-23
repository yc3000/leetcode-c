#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
searchInsert (int *nums, int numSize, int target)
{
  int a = 0, b = numSize - 1;
  int mid;

  while (a <= b)
    {
      mid = (a + b) / 2;
      if (nums[mid] == target)
        {
          return mid;
        }
      else if (target < nums[mid])
        {
          b = mid - 1;
        }
      else if (target > nums[mid])
        {
          a = mid + 1;
        }
    }
  return a;
}

int
main ()
{
  int nums[] = { 1, 3, 6, 7 };
  int target = 5;
  int ret = searchInsert (nums, sizeof (nums) / sizeof (int), target);
  printf ("%d", ret);
}
