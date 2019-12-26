#include <iostream>
#include <vector>
#include <queue>


class Node {
public:
    Node(const std::string s, const char c) : str(s+ c) {
        num_open = std::count(str.begin(), str.end(), '(');
        num_close = std::count(str.begin(), str.end(), ')');
    }
    std::string str;
    int num_open;
    int num_close;
};


class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        // do BFS
        std::vector<std::string> ret;
        std::queue<Node> q;
        q.push(Node("", '('));
        while (! q.empty()) {
            Node node = q.front(); q.pop();
            if (node.num_open < n) {
                q.push(Node(node.str, '('));
            }
            if (node.num_close < node.num_open) {
                q.push(Node(node.str, ')'));
            }
            if (node.str.size() == n * 2) {
                ret.push_back(node.str);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::vector<std::string> vs = s.generateParenthesis(3);
    for (std::string s : vs) {
        std::cout << s << std::endl;
    }
    return 0;
}