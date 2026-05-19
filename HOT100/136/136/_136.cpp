#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int King = nums[0];
        int HP = 0;
        for (int x : nums)
        {
            if (HP == 0)
            {
                King = x;
                HP = 1;
            }
            else
            {
                if (x == King) HP++;
                else HP --;
            }
        }
        return King;
    }
};
