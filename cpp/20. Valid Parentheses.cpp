class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(!n)return true;
        map<char, char> left_to_right = {{'{', '}'},{'[', ']'},{'(', ')'}};
        stack<char> mystack;
        mystack.push(s[0]);
        for(int i = 1;i < n;i++){
            if(!mystack.empty()&&left_to_right[mystack.top()] == s[i])mystack.pop();
            else mystack.push(s[i]);
        }
        if(mystack.empty())return true;
        else return false;
    }
};
