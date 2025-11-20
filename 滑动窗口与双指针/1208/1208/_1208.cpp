#include <stdio.h>
#include <string>   
#include <vector>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        vector<int> cost(n);
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cost[i] = abs(s[i] - t[i]);
            if (abs(s[i] - t[i]) > maxCost) flag++;
        }
        if (flag == n) return  1;

        int sum = 0;
        int ans = -1;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            sum += cost[i];
            while (sum > maxCost)
            {
                sum -= cost[left++];
            }
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
int main()
{
    
}