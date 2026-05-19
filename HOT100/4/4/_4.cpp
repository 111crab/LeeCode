#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 始终分割小的数组，减少二分范围
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // 此题为寻找分割线，所以 right = m，这代表 m 个数字我们可以取 （0 ~ m + 1）个分割线
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        
        while (left <= right)
        {
            // i 代表 nums1 的左边应该有多少个数字，也代表着分割线的虚拟位置。j 同理
            // j 根据 i 的个数动态调整，他两的个数和应当为 m + n 的一半或者 比右边多 1 个
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i;
            
            // L1 代表 nums1 的 [分割线] 的左边数的值，R1 代表 nums1 的 [分割线] 的右边数的值
            // 若 i = 0 代表 nums1 的左边一个数字不要，但是为了方便后续的 max 计算，取值负无穷
            // 若 i = m 代表 nums1 的左边要整个 m 个，但是为了方便后续的 min 计算，取值正无穷
            // j 同理
            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            // find !!
            if (L1 <= R2 && L2 <= R1)
            {
                if ((m + n) % 2 == 1) return max(L1, L2);
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }

            // 二分的方法，缩小分割线的取值
            if (L1 > R2)
            {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }
        // 理论上无法走到这
        return .0f;
    }
};