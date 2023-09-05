Leetcode Problem 

Valid Parentheses


Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true


CODE:-
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                bracket.push(ch);
            } else {
                if (!bracket.empty()) {
                    char top = bracket.top();
                    if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                        bracket.pop();  // Remove the matching opening bracket
                    } else {
                        return false;  // Mismatched brackets
                    }
                } else {
                    return false;  // Closing bracket without a matching opening bracket
                }
            }
        }

        return bracket.empty();  // Check if all brackets were matched
    }
};
