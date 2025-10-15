#include "main.h"
#include<iostream>
#include <vector>
using namespace std;

class Solution_Positive {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum = 0,ans = 0;
        int n = cardPoints.size();
        for (int i =0; i < k; i++)
        {
            sum = sum + cardPoints[i];
        }
        ans = sum;
        for (int i = 1; i <= k; i++)
        {
            sum = sum + cardPoints[n-i] - cardPoints[k-i];
            ans = max(ans,sum);
        }
        return ans;
    }
};

class Solution_Negative {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0,Min_Of_K = INT_MAX, all_point = 0;
        int n = cardPoints.size();
        for (int i = 0; i < cardPoints.size(); i++)
        {
            all_point += cardPoints[i];
        }
        if (n==k) return all_point;
        for (int i = 0; i < cardPoints.size(); i++)
        {
            sum = sum + cardPoints[i];

            int left = i - (n-k) + 1;
            if (left < 0) continue;
·   
            Min_Of_K = min(Min_Of_K, sum);
            sum -= cardPoints[left];
        }
        return all_point - Min_Of_K;
    }
};

int main()
{
    Solution_Positive sol;
    vector<int> cardPoints = {96,90,41,82,39,74,64,50,30};
   // cout<<sol.maxScore(cardPoints, 8);
   // cout<<endl;
    Solution_Negative sols;
    cout<<sols.maxScore(cardPoints, 8);
}