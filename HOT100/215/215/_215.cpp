#include <ctime>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    // 为何 j 的位置就是最终的中枢元素的最终位置？
    // 因为模拟过后就知道，i 最终停止的位置一定是右半边的第一个（右半边全大于等于中枢），而 j 会是左半边的最后一个（左半边全部小于等于中枢）
    // 所以 你和 j 交换，就代表着把 [中枢] 与 [一个小于中枢的] 数字交换，正好这个 [中枢] 就是在 left ，所以交换过后也不会打乱 左边 < pvoit < 右边的布局
    int partition(vector<int>& nums, int left, int right)
    {
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];
        swap(nums[left], nums[pivotIndex]);
        int i = left + 1, j = right;
        while (true)
        {
            while (i <= j && nums[i] < pivot) i++;
            while (i <= j && nums[j] > pivot) j--;
            if (i >= j)
            {
                break;
            }
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[j], nums[left]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int left = 0, right = nums.size() - 1;
        int targetIndex = nums.size() - k;
        while (left <= right)
        {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == targetIndex) return nums[pivotIndex];
            else if (pivotIndex > targetIndex) right = pivotIndex - 1;
            else left = pivotIndex + 1;
        }
        return 0;
    }
    // min-heap 写法
    int findKthLargest_minHeap(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num :nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
    
};