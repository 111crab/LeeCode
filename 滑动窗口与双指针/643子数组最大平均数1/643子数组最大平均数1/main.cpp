#include "main.h"
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            int left = i - k + 1 ;
            if (left < 0) continue;
            ans = max(ans,sum/k);

            sum -= nums[left];
        }

        return ans;
    }
};