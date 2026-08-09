class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int, vector<int>> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) maxHeap.push(cnt);
        }

        int TIME = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            TIME++;

            if (maxHeap.empty())
                TIME = q.front().second;
            else {
                int remCycles = maxHeap.top() - 1;
                maxHeap.pop();

                if (remCycles > 0) q.push({remCycles, TIME + n});
            }

            if (!q.empty() && q.front().second == TIME) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return TIME;
    }
};
