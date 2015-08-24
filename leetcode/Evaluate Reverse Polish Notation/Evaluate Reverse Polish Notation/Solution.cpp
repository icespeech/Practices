#include "Solution.h"
#include <stack>
#include <cstdlib>
using std::vector;
using std::string;
using std::stack;

int Solution::evalRPN(vector<string>& tokens)
{
    if (tokens.size() == 0) return 0;
    if (tokens.size() == 1) return atoi(tokens[0].c_str());

    stack<int> numbers;
    stack<char> operators;

    for (auto token : tokens)
    {
        if (token.compare("+")*token.compare("-")*token.compare("*")*token.compare("/") == 0)
        {
            operators.push(token[0]);
            while (numbers.size() > 1 && operators.size() > 0)
            {
                int op2 = numbers.top();
                numbers.pop();
                int op1 = numbers.top();
                numbers.pop();

                switch (operators.top())
                {
                case '+': numbers.push(op1 + op2); break;
                case '-': numbers.push(op1 - op2); break;
                case '*': numbers.push(op1 * op2); break;
                case '/': numbers.push(op1 / op2); break;
                }
                operators.pop();
            }
        }
        else
            numbers.push(atoi(token.c_str()));
    }
    return numbers.top();
}