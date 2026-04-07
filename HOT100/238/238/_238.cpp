#include <vector>
using namespace std;
class Solution {
public:
    // 计算前后缀
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = 1;
        suffix[0] = 1;
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] * nums[i];
        }
        // !!!此处 suf[i] 的定义为：后 i 个元素的乘积
        for (int i = 0; i < n; i++)
        {
            suffix[i + 1] = suffix[i] * nums[n - i - 1]; 
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix[i] * suffix[n - i - 1];
        }
        return ans;
    }
    // 优化空间 o(1), 返回数组不视为额外空间
    vector<int> productExceptSelf_best(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,1);
        // !!!此处 suf[i] 的定义为：i 右侧所有元素的乘积！
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1]; 
        }
        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            suffix[i] *= prefix;
            prefix *= nums[i];
        }
        return suffix;
    }
};