#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1 , left = 0;
        int ans = INT_MIN;
        while (left < right)
        {
            ans = max(ans , (right - left) * min(height[left], height[right]));
            height[left] < height[right] ? left++ : right-- ;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    s.maxArea(v);
}