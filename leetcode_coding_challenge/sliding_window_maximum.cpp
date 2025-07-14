class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for (int i=0;i<nums.size();i++) {
            pq.push({nums[i], i});

            if (i >= k-1) { // when the window is ready
                while (pq.top().second <= i-k) { 
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};