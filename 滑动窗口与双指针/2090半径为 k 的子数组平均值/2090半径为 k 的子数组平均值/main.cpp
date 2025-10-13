#include "main.h"


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs(nums.size(),-1);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            int left = i - 2 * k ;
            if (left < 0)
            {
                continue;
            }
            

                avgs[i-k] = sum / (2*k+1);
    
            
            sum -= nums[left];
            
        }
        
        return avgs;
    }
};

int main(){


    Solution s;
    vector<int> nums = { 7,4,3,9,1,8,5,2,6};
    vector<int> avgs = s.getAverages(nums,3);

    for (int i = 0; i < avgs.size(); i++)
    {
        cout << avgs[i] << " ";
    }
    
}