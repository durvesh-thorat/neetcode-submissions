class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());
        int length = 1;
        int maxLen = 0;
        vector<int> len;
        for (const auto& num : s) {
            if (!s.contains(
                    num - 1)) { // Sequence Starting Point(SSP) = num identified
                int temp = num;
                while (true) {
                    if (s.contains(++temp))
                        length++;
                    else
                        break;
                }
                maxLen = max(maxLen, length);
                length = 1;
            }
        }
        
        return maxLen;
    }
};
