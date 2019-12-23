#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() == 0) {
            return "";
        }
        int max_start = -1;
        int max_length = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            std::pair<int, int> p = search_palindrome(s, i, 1);
            if (p.second > max_length) {
                max_start = p.first;
                max_length = p.second;
            }
        }
        for (int i = 0 ; i < s.length() - 1 ; i++) {
            if (s[i] != s[i + 1]) {
                continue;
            }
            std::pair<int, int> p = search_palindrome(s, i, 2);
            if (p.second > max_length) {
                max_start = p.first;
                max_length = p.second;
            }
        }
        if (max_start == -1) {
            return "";
        }
        return s.substr(max_start, max_length);
    }

    std::pair<int, int> search_palindrome(std::string s, int start, int length) {
        int ret_start = start;
        int ret_length = length;

        while (true) {
            int end = start + length - 1;
            if (start == 0 || end == s.length() - 1) {
                if (s[start] == s[end]) {
                    if (length > ret_length) {
                        ret_length = length;
                        ret_start = start;
                    }
                    break;
                }
            }
            if (s[start] != s[end]) {
                start += 1;
                length -= 2;
                if (length > ret_length) {
                    ret_length = length;
                    ret_start = start;
                }
                break;
            }
            start -= 1;
            length += 2;
        }
        return std::pair<int, int>(ret_start, ret_length);
    }
};


class Solution2 {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() == 0) {
            return "";
        }
        std::string max_palindrome;
        for (int i = 0 ; i < s.length() ; i++) {
            int start = i;
            int end = i;
            std::string p = search_palindrome(s, i, i);
            if (p.length() > max_palindrome.length()) {
                max_palindrome = p;
            }
        }
        for (int i = 0 ; i < s.length() - 1 ; i++) {
            if (s[i] != s[i + 1]) {
                continue;
            }
            std::string p = search_palindrome(s, i, i + 1);
            if (p.length() > max_palindrome.length()) {
                max_palindrome = p;
            }
        }
        return max_palindrome;
    }

    std::string search_palindrome(std::string s, int start, int end) {
        std::string max_palindrome = start - end == 0 ? "" : s.substr(start, end - start + 1);
        while (true) {
            if (start == 0 || end == s.length() - 1) {
                if (s[start] == s[end]) {
                    std::string substr = s.substr(start, end - start + 1);
                    if (substr.length() > max_palindrome.length()) {
                        max_palindrome = substr;
                    }
                    break;
                }
            }
            if (s[start] != s[end]) {
                std::string substr = s.substr(start + 1, end - start - 1);
                if (substr.length() > max_palindrome.length()) {
                    max_palindrome = substr;
                }
                break;
            }
            start--;
            end++;
        }
        return max_palindrome;
    }
};

int main() {
    Solution s;
    std::string p = s.longestPalindrome("babad");
    std::cout << p << std::endl;
    return 0;
}