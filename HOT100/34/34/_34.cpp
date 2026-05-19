#include <vector>
using namespace std;


class Solution {
public:
    int low_bound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        int index1 = low_bound(nums, target);
        if (index1 >= nums.size() || nums[index1] != target) return result;
        int index2 = low_bound(nums, target + 1);
        result = {index1, index2 - 1};
        return result;
    }
};