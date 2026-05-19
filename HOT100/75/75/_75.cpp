#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N0 = 0;
        int N1 = 0;
        for (int &x : nums)
        {
            if (x == 0) N0++;
            if (x == 1) N1++;
            x = 2;
        }
        for (int i = 0; i < N0 + N1; i++)
        {
            if (i < N0) nums[i] = 0;
            else nums[i] = 1;
        }
    }
};