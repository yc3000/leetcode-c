#include <algorithm>
#include <stdio.h>
#include <vector>

class Solution
{
public:
  int
  searchInsert (std::vector<int> &nums, int target)
  {
    // 奇怪, 这是有两个补全吗?
    auto iter = std::find_if (
        nums.begin (), nums.end (),
        [target] (const int &elem) -> bool { return elem >= target; });
    return iter - nums.begin ();
  }
};

int
main ()
{
  Solution s;
  std::vector<int> vec{ 1, 3, 5, 6 };
  int target = 5;
  int ret = s.searchInsert (vec, target);
  printf ("%d\n", ret);
}
