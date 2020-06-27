#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

void evaluateStackTops(std::stack<int>& numbers, std::stack<char>& operations)
{
    int operand1 = 0, operand2 = 0;
    operand2 = numbers.top();
    numbers.pop();
    operand1 = numbers.top();
    numbers.pop();
    switch (operations.top())
    {
        case '+':
            numbers.push(operand1 + operand2);
            break;
        case '-':
            numbers.push(operand1 - operand2);
            break;
        case '*':
            numbers.push(operand1 * operand2);
            break;
        case '/':
            numbers.push(operand1 / operand2);
            break;
    }
    operations.pop();
}

double readAndEvaluate(const std::string& ins)
{
    const char DECIMAL = '.';
    const char RIGHT_PARENTHESIS = ')';

    std::stack<int> numbers;
    std::stack<char> operations;


    for(int i=0; i < ins.length(); i++)
    {
        if(isdigit(ins[i]) || (ins[i] == DECIMAL))
        {
            numbers.push(ins[i]-'0');
        }
        else if(strchr("+-*/",ins[i]) != NULL)
        {
            operations.push(ins[i]);
        }
        else if(ins[i] == RIGHT_PARENTHESIS)
        {
            evaluateStackTops(numbers,operations);
        }
    }

    return numbers.top();
}
int main ()
{
    double answer;
    //std::cout << "Type a fully parenthesized arithmetic expression:" << std::endl;
    answer = readAndEvaluate(std::string("(((3*2)+(1+2))/3)"));
    std::cout << "That evaluates to " << answer << std::endl;

    return EXIT_SUCCESS;
}
