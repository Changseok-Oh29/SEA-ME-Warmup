#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        vector<int> rowNums;
        vector<vector<int>> seatMap;
        
        for (int i=0;i<reservedSeats.size();i++) {
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            bool found = false;
            for (int i=0;i<rowNums.size();i++) {
                if (rowNums[i] == r) {
                    seatMap[i].push_back(c);
                    found = true;
                    break;
                }
            }
            if(!found) {
                rowNums.push_back(r);
                seatMap.push_back(vector<int>{c});
            }
            
        }

        int answer = (n - rowNums.size()) * 2;

        for (int i=0;i<rowNums.size();i++) {
            int seats[11] = {0};
            for (int s : seatMap[i]) {
                seats[s] = 1;
            }

            bool left = true;
            bool middle = true;
            bool right = true;
            for (int j=2;j<=5;j++) {
                if (seats[j]) {
                    left = false;
                }
            }
            for (int j=4;j<=7;j++) {
                if (seats[j]) {
                    middle = false;
                }
            }
            for (int j=6;j<=9;j++) {
                if (seats[j]) {
                    right = false;
                }
            }

            if (left && right) {
                answer += 2;
            }
            else if (left || middle || right) {
                answer += 1;
            }
        }

        return answer;

    }
};