#include "main.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>


class Solution {
public:
    int minArrivalsToDiscard(std::vector<int>& arrivals, int w, int m) {
        int ans = 0;
        std::unordered_map<int, int> mp;
        for (int i = 0; i < arrivals.size(); i++)
        {
            if (mp[arrivals[i]] == m)
            {
                arrivals[i] = -1;
                ans++;
            }
            else
            {
                mp[arrivals[i]] ++;
            }
            
            int left = i-w+1;
            if (left < 0) continue;

            mp[arrivals[left]] --;
            
        }
        return ans;
    }
};


int main()
{   Solution s;
    std::vector<int> arrivals = { 1,2,3,3,3,4};
    std::cout<<s.minArrivalsToDiscard(arrivals, 3, 2);
}