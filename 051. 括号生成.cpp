// 051. 括号生成.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution1 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        string current;
        GenerateAll(current, n * 2, result);
        return result;
    }
private:
    void GenerateAll(string& current, int n, vector<string>& result)
    {
        if (n == current.size())
        {
            if (IsVaild(current))
            {
                result.emplace_back(current);
            }

            return;
        }

        current.push_back('(');
        GenerateAll(current, n, result);
        current.pop_back();
        current.push_back(')');
        GenerateAll(current, n, result);
        current.pop_back();
    }

    bool IsVaild(const string& str)
    {
        int balance = 0;
        for (auto& it : str)
        {
            if (it == '(')
            {
                ++balance;
            }
            else
            {
                --balance;
            }

            if (balance < 0)
            {
                return false;
            }
        }

        return balance == 0;
    }
};

class Solution2
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        backtrack(current, result, 0, 0, n);
        return result;
    }
private:
    void backtrack(string& current, vector<string>& result, int left, int right, int n)
    {
        if (current.size() == n * 2)
        {
            result.emplace_back(current);
            return;
        }

        if (left < n)
        {
            current.push_back('(');
            backtrack(current, result, left + 1, right, n);
            current.pop_back();
        }

        if (right < left)
        {
            current.push_back(')');
            backtrack(current, result, left, right + 1, n);
            current.pop_back();
        }
    }
};

int main()
{
    Solution2 ss;
    vector<string> ans = ss.generateParenthesis(3);
    return 0;
}
