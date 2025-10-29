#include "Stack.h"

void createStack(Stack* stack, std::string value) {
    stack->top = new StackElement{ value, nullptr };
}

void StackPush(Stack* stack, std::string value) {
    StackElement* newElement = new StackElement{ value, stack->top };
    stack->top = newElement;
}

StackElement* StackPop(Stack* stack) {
    // выводить элемент
    StackElement* deleteElement = stack->top;
    stack->top = deleteElement->next;
    StackElement* result = new StackElement{ deleteElement->value, nullptr };
    delete deleteElement;
    return result;
}

std::ostream& operator<< (std::ostream& os, Stack stack) {
    while (true) {
        if (stack.top->next == nullptr) {
            os << stack.top->value;
            break;
        }
        os << stack.top->value << " ";
        stack.top = stack.top->next;
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, StackElement* stackElement) {
    os << stackElement->value;
    return os;
}

void exportStack(Stack stack, std::string path) {
    std::ofstream out;
    out.open(path);
    if (out.is_open()) {
        out << stack;
    }
    out.close();
}

Stack* importStack(std::string path) {
    Stack* result = new Stack;
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        std::string data;
        in >> data;
        createStack(result, data);
        StackElement* nowElement = result->top;
        while (in >> data) {
            nowElement->next = new StackElement{ data, nullptr };
            nowElement = nowElement->next;
        }
    }
    in.close();
    return result;
}