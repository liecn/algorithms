class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits=="")return res;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //initialize res
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> midres;
            //map
            string chars = charmap[digits[i] - '0'];
            for (int c = 0; c < chars.size();c++)
                // add all chars
                for (int j = 0; j < res.size();j++)
                    // add char
                    midres.push_back(res[j]+chars[c]);
            res = midres;
        }
        return res;
    }
};
