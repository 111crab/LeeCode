#include <unordered_map>
#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int ans = -1;
        unordered_map<int,int> cnt;
        int left = 0;
        for (int i = 0 ; i < fruits.size(); i++)
        {
            int cur_fruit = fruits[i];
            cnt[cur_fruit]++;
            while (cnt.size() > 2)
            {
                if (--cnt[fruits[left]] == 0)
                {
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans , i - left + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> fruits = {0,1,2,2};
    cout<< s.totalFruit(fruits);
}
