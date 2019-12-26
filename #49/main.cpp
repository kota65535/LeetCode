#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (std::string s : strs) {
            std::string sorted(s);
            std::sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s);
        }
        std::vector<std::vector<std::string>> ret;
        for (auto it : map) {
            ret.push_back(it.second);
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto v : s.groupAnagrams(strs)) {
        for (std::string s : v) {
            std::cout << s << " " ;
        }
        std::cout << std::endl;
    }
    return 0;
}