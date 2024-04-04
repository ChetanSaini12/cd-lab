#include <iostream>
#include <cstring>

#define SUCCESS 1
#define FAILED 0

// Function prototypes
int E(), Edash(), T(), Tdash(), F();

const char *cursor;
char string[64];

int main() {
    std::cout << "Enter the string" << std::endl;
    std::cin >> string;
    cursor = string;
    std::cout << std::endl;
    std::cout << "Input\t\t\t Action" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    if (E() && *cursor == '\0') {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "String is successfully parsed" << std::endl;
        return 0;
    } else {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Error in parsing String" << std::endl;
        return 1;
    }
}

int E() {
    if (T()) {
        if (Edash())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int Edash() {
    if (*cursor == '+') {
        cursor++;
        if (T()) {
            if (Edash())
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        return SUCCESS;
    }
}

int T() {
    if (F()) {
        if (Tdash())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int Tdash() {
    if (*cursor == '*') {
        cursor++;
        if (F()) { 
            if (Tdash())
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        return SUCCESS;
    }
}

int F() {
    if (*cursor == '(') {
        cursor++;
        if (E()) {
            if (*cursor == ')') {
                cursor++;
                return SUCCESS;
            } else
                return FAILED;
        } else
            return FAILED;
    } else if (*cursor == 'i') {
        cursor++;
        return SUCCESS;
    } else
        return FAILED;
}
