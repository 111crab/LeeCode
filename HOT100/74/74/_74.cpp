#include <vector>
using namespace std;

class Solution {
public:
    int low_bound (vector<int> &nums, int target)
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
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int index = -1;
        for (int i = 0 ; i < m; i++)
        {
            if (target == matrix[i][n - 1]) return true;
            if (target < matrix[i][n - 1])
            {
                index = i;
                break;
            }
        }
        if (index == -1) return false;
        int ans = low_bound(matrix[index], target);
        return matrix[index][ans] == target;
    }
};