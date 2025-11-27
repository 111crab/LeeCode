#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(std::string answerKey, int k) {
        int ans = -1;
        int n = answerKey.size();
        int cur_T = 0,cur_F = 0;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            char c = answerKey[i];
            if (c == 'T') cur_T++;
            else cur_F++;

            while (cur_T > k && cur_F > k)
            {
                if (answerKey[left] == 'T') cur_T--;
                else cur_F--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
