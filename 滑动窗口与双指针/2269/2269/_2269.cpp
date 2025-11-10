#include<iostream>
#include <string>
#include <vector>
using namespace std;




class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int flag = num;
        int ans = 0;
        vector<int> nums;
        // turn int into the vector
        while (flag>0)
        {
            
                nums.push_back(flag%10); 
            
            flag /= 10;
        }
        // calculate the index
        int index = 1;
        for (int i = 1; i <= k-1; i++)
        {
            index *= 10;
        }
        // Reverse the nums
        int temp = 0;
        for (int i = 0; i < nums.size() / 2 ; i++)
        {
            temp = nums[i];
            nums[i] = nums[nums.size()-i-1];
            nums[nums.size()-i-1] = temp;
        }
        // slip the windows
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum*10 + nums[i];

            int left = i - k + 1;
            if (left < 0) continue;
            if (sum == 0)
            {
                continue;
            }
            else
            {
                if (num % sum == 0) ans++;
                sum = sum % index;
            }
   
        }
        return ans;
    }
};


class lingshen {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for (int i = k; i <= s.size(); i++) {
            int x = stoi(s.substr(i - k, k)); // 长为 k 的子串
            if (x > 0 && num % x == 0) { // 子串能整除 num
                ans++;
            }
        }
        return ans;
    }
    
    /*作者：灵茶山艾府
    链接：https://leetcode.cn/problems/find-the-k-beauty-of-a-number/solutions/1496449/mo-ni-by-endlesscheng-burh/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
};




int main()
{
    Solution s;
    cout<< s.divisorSubstrings(2,1)<<" ";
}