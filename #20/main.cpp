#include <iostream>
#include <stack>


class Solution {
public:
    bool isValid(std::string s) {

        std::stack<char> stack;

        for (char c : s) {
            // push stack if braces open
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    // no open brace
                    return false;
                }
                char t = stack.top(); stack.pop();
                if ((c == ')' && t == '(')
                    || (c == '}' && t == '{')
                    || (c == ']' && t == '[')) {
                    // ok: brace matches
                } else {
                    // ng: brace does not match
                    return false;
                }
            }
        }
        // check if open brace remains
        return stack.empty();
    }
};

int main() {
    Solution s;
    std::cout << s.isValid("]") << std::endl;
    return 0;
}