#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int sum = 0;
        int left = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            sum += num;
            cnt[num]++;
            while (cnt[num] > 1)
            {
                sum -= nums[left];
                cnt[nums[left]]--;
                left++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};


int main()
{
    
}