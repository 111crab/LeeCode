#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        int sum= 0 ;
        int r = k > 0 ? k : n-1; // 确定不同情况下，初始窗口的右端在哪。
        k = abs(k);
        // 计算第一个窗口总值
        for (int i = (r-k+1) ;i <= r;i++) sum += code[i];
        // 直接开滑
        for (int i = 0; i < n; i++)
        {
            ans[i] = sum;
            sum += code[(r+1)%n] - code[(r-k+1) % n]; // 向右挪
            r++;
        }
        return ans;
    }
};

int main()
{
    vector<int> code = {5,7,1,4};
    Solution s;
    vector<int> ans = s.decrypt(code,3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}