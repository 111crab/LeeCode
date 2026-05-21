#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int ,vector<int>, greater<int>> right;
public:
    // 中位数：数据流最中间的数字，最好的处理方法就是，将他们分钟左右两部分，让他们在数量上 left = right 或者 left - right = 1
    // 而在大小上 left < right
    // 中位数自然就是 left 中的最大数字（数据流为 odd），或者是 （left 的最大 + right 的最小）/ 2.0 （数据流为 even）
    MedianFinder() {
        
    }
    // 那么在插入的时候如何维护这种大小和数量关系呢？
    void addNum(int num) {
        // 在二者数量相等的时候，若是 num 为一个小数插入 left 还好，但是 num 是一个大数字插入 right 就会让右边多出 1（两种情况）
        // 我们就需要让 right 弹出他的最小值给 left 这样就会在大小和数量上都符合规矩（这也是我们使用大根堆维护 left，小根堆维护 right 的原因）
        // 所以干脆在这种情况下，我们直接插入在 right 再弹出一个给 left，这样就合并了两种情况
        if (right.size() == left.size())
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        // 这里就是（数量）left - right = 1 的情况，同理也会出现两种类似情况
        // 不论如何插入 left 然后弹出堆顶给 right 就好了
        else
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if ((right.size() + left.size()) % 2 == 1)
        {
            return left.top();
        }
        else return (right.top() + left.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */