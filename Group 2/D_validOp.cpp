
#include <iostream>
#include <string>

int main()
{
    std::string op;
    std::cout << "Enter an operator: ";
    std::cin >> op;

    switch (op[0])
    {
    case '+':
        std::cout << "Addition" << std::endl;
        break;
    case '-':
        std::cout << "Subtraction" << std::endl;
        break;
    case '*':
        std::cout << "Multiplication" << std::endl;
        break;
    case '/':
        std::cout << "Division" << std::endl;
        break;
    case '=':
        if (op.length() == 1)
            std::cout << "Assignment" << std::endl;
        else if (op == "==")
            std::cout << "Equal To" << std::endl;
        else if (op == "!=")
            std::cout << "Not Equal To" << std::endl;
        break;
    case '<':
        if (op == "<")
            std::cout << "Less Than" << std::endl;
        else if (op == "<=")
            std::cout << "Less Than or Equal To" << std::endl;
        break;
    case '>':
        if (op == ">")
            std::cout << "Greater Than" << std::endl;
        else if (op == ">=")
            std::cout << "Greater Than or Equal To" << std::endl;
        break;
    case '!':
        if (op == "!")
            std::cout << "Logical NOT" << std::endl;
        else if (op == "!=")
            std::cout << "Not Equal To" << std::endl;
        break;
    case '&':
        if (op == "&&")
            std::cout << "Logical AND" << std::endl;
        else if (op == "&")
            std::cout << "Bitwise AND" << std::endl;
        break;
    case '|':
        if (op == "||")
            std::cout << "Logical OR" << std::endl;
        else if (op == "|")
            std::cout << "Bitwise OR" << std::endl;
        break;
    default:
        std::cout << "Invalid Operator" << std::endl;
    }

    return 0;
}