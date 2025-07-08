using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> myMap;

        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";

        vector<string> myReturn;

        getLetterCombinations(myReturn,"",0,myMap,digits);

        return myReturn;
    }

    void getLetterCombinations(vector<string>& myReturn, string currentString, int index, unordered_map<char, string>& myMap, const string& digits) { // answer, current combination string, index, myMap(number, letter matching), digits
        if (currentString.size() == digits.size()) { //currentString과 digits의 크기를 같도록함. -> 종료 조건
            myReturn.push_back(currentString);
            return;
        }

        string myLetters = myMap[digits[index]];

        for (const auto& element:myLetters) {
            currentString.push_back(element);
            getLetterCombinations(myReturn,currentString,index+1,myMap,digits); //recursion

            currentString.pop_back();
        }
    }
};