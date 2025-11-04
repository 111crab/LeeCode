#include<iostream>
#include <bitset>   // 用于 bitset
#include <string>   // 用于 string
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            auto bin = bitset<32>(i).to_string(); // 把 i 转成 32 位无符号数，例如 5 ："00000000000000000000000000000101"
            bin = bin.substr(bin.find('1')); // find：找到并截取第一个 1 的下标。 然后把 bin 变成纯二进制
            if (s.find(bin) == string::npos) // 在 s 中找 bin 这个子串，找不到就 false
                return false;
        }
        return true;
    }
};

// find重载（“要找到东西”，“从哪个位置找，默认为0”），找到都是返回下标。