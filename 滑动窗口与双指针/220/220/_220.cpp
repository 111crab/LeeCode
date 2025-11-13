#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 超时：灵神公式 + 双循环
/*class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        int window = indexDiff + 1;
        int difference = 0;
        for (int i = 0;i < nums.size();i++)
        {
            int left = i - window + 1;
            if (left < 0)
            {
                for (int j = i - 1;j >= 0;j--)
                {
                    difference = abs(nums[i] - nums[j]);
                    if (difference <= valueDiff) return true;
                }
                continue;
            }
            else
            {
                for (int j = i - 1;j >= left;j--)
                {
                    difference = abs(nums[i] - nums[j]);
                    if (difference <= valueDiff) return true;
                }
            }
        }
        return false;
        
    }
};*/

// 有序集合 + 二分查找 AC

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> rec;
        
        for (int i = 0; i < n; i++)
        {
            // lower_bound: 找到第一个大于等于 nums[i] - valueDiff 的迭代器，这种寻找是二分的。
            auto it = rec.lower_bound(nums[i] - valueDiff);
            // 判断 it 是不是当前的 i 自己，而且是不是小于 nums[i] + valueDiff
            if (it != rec.end() && *it <= nums[i] + valueDiff ) return true;
            // 插入有序集合set，入队
            rec.insert(nums[i]);
            // 出队（满足窗口情况下）
            if (i >= indexDiff) rec.erase(nums[i - indexDiff]); 
        }
        return false;
    }
};