// 电话号码的字母组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//示例 1：
//
//输入：digits = "23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//示例 2：
//
//输入：digits = ""
//输出：[]
//示例 3：
//
//输入：digits = "2"
//输出：["a", "b", "c"]

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    static std::vector<string> LetterCombinations(std::string digits)
    {
        std::vector<std::string> combinations;
        if (digits.empty()) 
        {
            return combinations;
        }
        std::unordered_map<char, std::string> phoneMap
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        std::string combination;
        backtrack(phoneMap, digits, 0, combination, combinations);
        return combinations;
    }

    static void backtrack(const std::unordered_map<char, std::string>& mmap, const std::string& digits, int index, std::string& combination, std::vector<std::string>& combinations)
    {
        if (index == digits.size())
        {
            combinations.emplace_back(combination);
            return;
        }

        const char digit = digits[index];
        const std::string& letters = mmap.at(digit);
        for (auto& iter : letters)
        {
            combination.push_back(iter);
            backtrack(mmap, digits, index + 1, combination, combinations);
            combination.pop_back();
        }
    }
};

int main()
{
    string digits = "23";
    std::vector<string> vec;
    vec = Solution::LetterCombinations(digits);

    for (auto iter : vec)
    {
        std::cout << iter << std::endl;
    }
    return 0;
}
