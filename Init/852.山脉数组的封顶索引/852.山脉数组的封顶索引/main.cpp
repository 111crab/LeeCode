#include "main.h"

#include <iostream>
#include <stdio.h>
#include <vector>

class Solution {
public:
    
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;

        while(left < right){
            int mid = (right + left)/2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            
            if (arr[mid] < arr[mid+1]){
                left = mid + 1;
            }
            else {
                right = mid;
            } 
        }

    }
};
int main()
{
    Solution s;
    std::vector<int> a{1, 3, 5, 7, 9, 5, 3, 2, 1};
    std::cout << s.peakIndexInMountainArray(a);
    
}
