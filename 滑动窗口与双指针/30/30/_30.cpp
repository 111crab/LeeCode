#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int word_len = words[0].size();
        int windows_len = words.size() * word_len;
        
        unordered_map<string, int> target_cnt;
        for (string word : words)
        {
            target_cnt[word]++;
        }

        vector<int> ans;

        for (int start = 0; start < word_len; start++) // 起始点从 0 - word_len-1 开划，这样是全面的答案
        {
            unordered_map<string, int> cnt;
            int overload = 0;
            // 右端点枚举
            for (int right = start + word_len - 1; right < s.size(); right += word_len) // 把串分成 word_len 一份，一个一个判断。
            {
                string in_word = s.substr(right - word_len + 1, word_len);
                if (cnt[in_word] == target_cnt[in_word]) overload++;
                cnt[in_word]++;
 
                int left = right - word_len + 1;
                if (left < 0) continue;

                if (overload == 0) // overload控制：如果多出了target中既定次数的词语，会触发超载。不论是否这个词在words中有无或者重复，因为答案target已经确定了。
                {
                    ans.push_back(left);
                }

                string out_word = s.substr(left, word_len);
                cnt[out_word]--;
                if (cnt[out_word] == target_cnt[out_word]) overload--;
                
            }
            
        }
        return ans;
    }
};




int main()
{
}