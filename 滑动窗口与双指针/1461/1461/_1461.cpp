#include<iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {

        string now;
        unordered_map<string, int> map;
        for (int i = 0; i < s.length(); i++)
        {
            // 入队
            now.push_back(s[i]);

            
            int left = i - k + 1;
            if (left < 0) continue;
            
            map[now]++;
            
            // 出队
            now = now.substr(1);
            
        }
        if (map.size() >= pow(2,k)) return true;
        else return false;
    }
};








int main()
{
    
}
