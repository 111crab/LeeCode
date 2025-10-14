#include "main.h"
#include "iostream"
using namespace std;
#include <string>

class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int ans = INT_MAX;
        int white = 0;
        for (int i = 0; i < blocks.size(); i++)
        {
            if (blocks[i] == 'W') ans++;

            if (i-k+1 < 0) continue;

            ans = min(ans, white);

            if (blocks[i-k+1] == 'W') ans--;
            
        }
        return ans;
    }
};
