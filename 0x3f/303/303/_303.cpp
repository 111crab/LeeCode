#include <vector>
using namespace std;

class NumArray {
    vector<int> s;
public:
    NumArray(vector<int>& nums) {
        s.resize(nums.size()+1);
        for (int i = 0 ; i < nums.size(); i++)
        {
            s[i + 1] = s[i] + nums[i]; 
        }
    }
    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};

