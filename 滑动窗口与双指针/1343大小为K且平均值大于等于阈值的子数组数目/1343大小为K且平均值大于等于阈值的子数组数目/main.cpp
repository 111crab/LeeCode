#include "main.h"
#include<iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        float sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            int left = i-k+1;
            if (left < 0) continue;

            if (sum/k >= threshold) ans++;

            sum -= arr[left];
            
        }

        return ans;
    }
};