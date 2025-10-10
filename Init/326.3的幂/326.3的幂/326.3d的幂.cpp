#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<3 && n!= 1) return false;
        else if (n ==1) return true;
        else if (n% 3 != 0) return false;
        else return isPowerOfThree(n/3);
    }
};

int main()
{
    Solution s;
    cout<<s.isPowerOfThree(45);
    return 0;
}