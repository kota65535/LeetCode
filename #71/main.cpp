#include <iostream>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        // add "/" to the path end if not
        if (path.find('/', path.size() - 1) == std::string::npos) {
            path += '/';
        }

        std::stack<std::string> dirs;
        while (! path.empty()) {
            auto pos = path.find('/');
            if (pos != std::string::npos) {
                std::string part = path.substr(0, pos);
                if (part == "." || part.empty()) {
                    // noop
                } else if (part == "..") {
                    if (! dirs.empty()) {
                        dirs.pop();
                    }
                } else {
                    dirs.push(part);
                }
            }
            path = path.substr(pos + 1);
        }

        if (dirs.empty()) {
            return "/";
        }
        std::string ret;
        while (! dirs.empty()) {
            std::string part = dirs.top() ; dirs.pop();
            ret.insert(0, "/" + part);
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::cout << s.simplifyPath("/a//b////c/d//././/..") << std::endl;
    return 0;
}