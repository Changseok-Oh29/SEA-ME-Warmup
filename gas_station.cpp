class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0; // total surplus
        int surplus = 0; // current surplus
        int S = 0; // starting point

        for (int i=0;i<n;i++) {
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0) { // current surplus < 0이면, 다음부터 다시 실행한다.
                surplus = 0;
                S = i+1;
            }
        }
        if (total_surplus < 0) return -1;
        else return S;
        
    }
};