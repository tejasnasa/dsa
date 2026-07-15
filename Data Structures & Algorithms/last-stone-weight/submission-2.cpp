class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;

        for (auto s: stones) {
            max_heap.push(s);
        }

        while (max_heap.size() > 1) {
            int a = max_heap.top();
            max_heap.pop();
            int b = max_heap.top();
            max_heap.pop();

            if (abs(a-b)>0) max_heap.push(abs(a-b));
        }

        return max_heap.size() ? max_heap.top() : 0;
    }
};
