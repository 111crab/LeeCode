#include <vector>
using namespace std;
class Solution
{
public:
    // 翻转数组
    void reverse(vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (n == 0) return;
        int ref = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, ref - 1);
        reverse(nums, ref, n-1);
    }
    // 示例 nums = 1,2,3,4,5  k = 2
    // 1) 5 4 3 2 1 - 全翻转
    // 2) 4 5 3 2 1 - 翻转前 k 个
    // 3) 4 5 1 2 3 - 翻转后 n - k 个 = ans
};