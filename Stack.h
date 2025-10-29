#pragma once

#include <iostream>
#include <fstream>

struct StackElement {
    std::string value;
    StackElement* next;
};

//StackElement* nullStackElement = new StackElement{ "", nullptr };

struct Stack {
    StackElement* top;
};

void createStack(Stack* stack, std::string value);

void StackPush(Stack* stack, std::string value);

StackElement* StackPop(Stack* stack);

std::ostream& operator<< (std::ostream& os, Stack stack);

std::ostream& operator<< (std::ostream& os, StackElement* stackElement);

void exportStack(Stack stack, std::string path);

Stack* importStack(std::string path);