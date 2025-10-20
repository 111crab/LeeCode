#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int answer = 0;
        int basic_sum = 0;
        int sum = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 0) basic_sum += customers[i];
        }
        
        answer = basic_sum;
        sum = basic_sum;
        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 1) sum += customers[i];
            
            int left = i - minutes + 1;
            if (left < 0) continue;

            answer = max(sum,answer);

            if (grumpy[left] == 1) sum -= customers[left];
            
        }
        return answer;
    }
};
