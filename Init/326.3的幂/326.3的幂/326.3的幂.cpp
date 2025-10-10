#include <stdio.h>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<3 && n!= 1) return false;
        else if (n ==1) return true;
        else return isPowerOfThree(n/3);
    }
};
int main() {
    Solution s;
    std::cout << s.isPowerOfThree(3) << std::endl;
}