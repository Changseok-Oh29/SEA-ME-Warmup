class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int half = n / 2;

        vector<int> acity, bcity;

        for (int i=0;i<n;i++) {
            if (costs[i][0] <= costs[i][1]) {
                acity.push_back(i);
            }
            else {
                bcity.push_back(i);
            }
        }

        vector<bool> A(n, false);

        if (acity.size() > half) { // if A has more than B

            vector<pair<int, int>> diffToIndex;
            for (int idx : acity) {
                int diff = costs[idx][1] - costs[idx][0];
                diffToIndex.push_back({diff, idx});
            }

            sort(diffToIndex.begin(), diffToIndex.end(), greater<>());

            for (int i=0;i<half;i++) {
                A[diffToIndex[i].second] = true;
            }
        }
        else { //if B has more than A
            int excess = bcity.size() - half;

            vector<pair<int, int>> diffToIndex;
            for (int idx : bcity) {
                int diff = costs[idx][0] - costs[idx][1];
                diffToIndex.push_back({diff, idx});
            }
            
            sort(diffToIndex.begin(), diffToIndex.end());

            for (int i=0;i<excess;i++) {
                A[diffToIndex[i].second] = true;
            }

            for (int idx : acity) {
                A[idx] = true;
            }
        }

        int answer = 0;
        for (int i=0;i<n;i++) {
            if (A[i]) {
                answer += costs[i][0];
            }
            else {
                answer += costs[i][1];
            }
        }

        return answer;
    }
};