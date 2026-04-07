#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); 
        // nums[i] 的理解：当前座位 i 上的学生的学号为 nums[i]
        for (int i = 0; i < n; i++)
        {
            // 读题能想到，本题答案只会在 [1,n] 之间的第一个缺失数字，或者在 n+1 出现
            // 所以只有学号在 [1,n] 之间的学生才有[资格]交换座位
            // 第三个判断：学号为 nums[i] 的学生，其真正座位 nums[i] - 1 上是否坐着自己真身 nums[i] 或者影分身 nums[i]，谁坐着都行。不是那我就有[资格]交换回自己的座位
            while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                int j = nums[i] - 1;
                swap(nums[i], nums[j]);
            }
        }
        // 位置 i:(0,n-1) 其正确的 学号为 i + 1:(1,n)
        for (int i = 0; i < n; i++)
        {
            // 看看哪个位置上没坐着本人
            if (nums[i] != i + 1) return i + 1;
        }
        // 都坐着，答案为 n + 1
        return n + 1;
    }
};