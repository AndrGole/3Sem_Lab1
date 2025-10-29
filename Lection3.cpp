#include <iostream>
#include <string>

#include "DoubleLinkedList.h"
#include "ForwardList.h"
#include "Massive.h"
#include "Queue.h"
#include "Stack.h"
#include "Tree.h"

int main() {
    DoubleLinkedList dList;
    CreateDL(&dList, "start");
    ForwardList fList;
    CreateFL(&fList, "start");
    Massive mass;
    createMassive(&mass, 10);
    Queue queue;
    createQueue(&queue, "start");
    Stack stack;
    createStack(&stack, "start");
    AVLTree tree;

    std::string commandText;

    int idx;
    Node2* currentn2 = nullptr;
    Node2* nextn2 = nullptr;
    DoubleLinkedList* newListDL = nullptr;
    ForwardList* newListFL = nullptr;
    Node* currentn = nullptr;
    Node* nextn = nullptr;
    int spasePos;
    std::string idxStr;
    Massive* newMass = nullptr;
    Queue* newQueue = nullptr;
    QueueElement* currentq = nullptr;
    QueueElement* nextq = nullptr;
    Stack* newStack = nullptr;
    StackElement* currents = nullptr;
    StackElement* nexts = nullptr;
    AVLTree* newTree = nullptr;

    newCommand:
    std::getline(std::cin, commandText);

    switch (commandText[0])
    {
    case 'D': {
        commandText.erase(0, 1);
        if (commandText.find("ADDAFTER") == 0) {
            commandText.erase(0, 9);
            spasePos = commandText.find(" ");
            if (spasePos == std::string::npos) {
                std::cout << "incorrect input, try input more than one parameter\n";
            }
            idxStr = commandText.substr(0, spasePos);
            commandText = commandText.substr(spasePos + 1);
            AddNode2(&dList, GetNode2(dList, idxStr), commandText);
        }
        else if (commandText.find("ADDBEFORE") == 0) {
            commandText.erase(0, 10);
            spasePos = commandText.find(" ");
            if (spasePos == std::string::npos) {
                std::cout << "incorrect input, try input more than one parameter\n";
            }
            idxStr = commandText.substr(0, spasePos);
            commandText = commandText.substr(spasePos + 1);
            AddNode2Before(&dList, GetNode2(dList, idxStr), commandText);
        }
        else if (commandText.find("PUSHBACK") == 0) {
            commandText.erase(0, 9);
            DLPushBack(&dList, commandText);
        }
        else if (commandText.find("PUSHFORWARD") == 0) {
            commandText.erase(0, 12);
            DLPushForward(&dList, commandText);
        }
        else if (commandText.find("DELAFTER") == 0) {
            commandText.erase(0, 9);
            DeleteNode2(&dList, GetNode2(dList, idxStr));
        }
        else if (commandText.find("DELBEFORE") == 0) {
            commandText.erase(0, 10);
            DeleteNode2Before(&dList, GetNode2(dList, idxStr));
        }
        else if (commandText.find("POPBACK") == 0) {
            commandText.erase(0, 7);
            DLPopBack(&dList);
        }
        else if (commandText.find("POPFORWARD") == 0) {
            commandText.erase(0, 10);
            DLPopForward(&dList);
        }
        else if (commandText.find("DELKEY") == 0) {
            commandText.erase(0, 7);
            DeleteNode2(&dList, commandText);
        }
        else if (commandText.find("PRINT") == 0) {
            commandText.erase(0, 5);
            std::cout << dList << std::endl;
        }
        else if (commandText.find("FIND") == 0) {
            commandText.erase(0, 5);
            try {
                idx = std::stoi(commandText);
                std::cout << GetNode2(dList, idx);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("IMPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                try {
                    newListDL = importDL(commandText);

                    currentn2 = dList.head;
                    while (currentn2 != nullptr) {
                        nextn2 = currentn2->next;
                        delete currentn2;
                        currentn2 = nextn2;
                    }

                    dList = *newListDL;
                    delete newListDL;
                }
                catch (const std::exception& e) {
                    std::cout << "Error during import: " << e.what() << std::endl;
                }
            }
        }
        else if (commandText.find("EXPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                exportDL(dList, commandText);
            }
        }
        break;
    }
    case 'F': {
        commandText.erase(0, 1);
        if (commandText.find("ADDAFTER") == 0) {
            commandText.erase(0, 9);
            spasePos = commandText.find(" ");
            if (spasePos == std::string::npos) {
                std::cout << "incorrect input, try input more than one parameter\n";
            }
            idxStr = commandText.substr(0, spasePos);
            commandText = commandText.substr(spasePos + 1);
            AddNode(fList, GetNode(fList, idxStr), commandText);
        }
        else if (commandText.find("ADDBEFORE") == 0) {
            commandText.erase(0, 10);
            spasePos = commandText.find(" ");
            if (spasePos == std::string::npos) {
                std::cout << "incorrect input, try input more than one parameter\n";
            }
            idxStr = commandText.substr(0, spasePos);
            commandText = commandText.substr(spasePos + 1);
            AddNodeBefore(&fList, GetNode(fList, idxStr), commandText);
        }
        else if (commandText.find("PUSHBACK") == 0) {
            commandText.erase(0, 9);
            FLPushBack(&fList, commandText);
        }
        else if (commandText.find("PUSHFORWARD") == 0) {
            commandText.erase(0, 12);
            FLPushForward(&fList, commandText);
        }
        else if (commandText.find("DELAFTER") == 0) {
            commandText.erase(0, 9);
            DeleteNode(fList, GetNode(fList, idxStr));
        }
        else if (commandText.find("DELBEFORE") == 0) {
            commandText.erase(0, 10);
            DeleteNodeBefore(&fList, GetNode(fList, idxStr));
        }
        else if (commandText.find("POPBACK") == 0) {
            commandText.erase(0, 7);
            FLPopBack(&fList);
        }
        else if (commandText.find("POPFORWARD") == 0) {
            commandText.erase(0, 10);
            FLPopForward(&fList);
        }
        else if (commandText.find("DELKEY") == 0) {
            commandText.erase(0, 7);
            DeleteNode(&fList, commandText);
        }
        else if (commandText.find("PRINT") == 0) {
            commandText.erase(0, 5);
            std::cout << fList << std::endl;
        }
        else if (commandText.find("FIND") == 0) {
            commandText.erase(0, 5);
            try {
                idx = std::stoi(commandText);
                std::cout << GetNode(fList, idx);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("IMPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                try {
                    newListFL = importFL(commandText);

                    currentn = fList.head;
                    while (currentn != nullptr) {
                        nextn = currentn->next;
                        delete currentn;
                        currentn = nextn;
                    }

                    fList = *newListFL;
                    delete newListFL;
                }
                catch (const std::exception& e) {
                    std::cout << "Error during import: " << e.what() << std::endl;
                }
            }
        }
        else if (commandText.find("EXPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                exportFL(fList, commandText);
            }
        }
        break;
    }
    case 'M': {
        commandText.erase(0, 1);
        if (commandText.find("INSERT") == 0) {
            commandText.erase(0, 7);
            spasePos = commandText.find(" ");
            if (spasePos == std::string::npos) {
                std::cout << "incorrect input, try input more than one parameter\n";
            }
            else {
                idxStr = commandText.substr(0, spasePos);
                try {
                    idx = std::stoi(idxStr);
                    commandText = commandText.substr(spasePos + 1);
                    insert(&mass, idx, commandText);
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                catch (...) {
                    std::cout << "Unknown error.\n";
                }
            }
        }
        else if (commandText.find("SET") == 0) {
            commandText.erase(0, 4);
            spasePos = commandText.find(" ");
            if (spasePos == std::string::npos) {
                std::cout << "incorrect input, try input more than one parameter\n";
            }
            else {
                idxStr = commandText.substr(0, spasePos);
                try {
                    idx = std::stoi(idxStr);
                    commandText = commandText.substr(spasePos + 1);
                    set(&mass, idx, commandText);
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                catch (...) {
                    std::cout << "Unknown error.\n";
                }
            }
        }
        else if (commandText.find("PUSHBACK") == 0) {
            commandText.erase(0, 9);
            pushBack(&mass, commandText);
        }
        else if (commandText.find("REMOVE") == 0) {
            commandText.erase(0, 7);
            try {
                int idx = std::stoi(commandText);
                remove(&mass, idx);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("SIZE") == 0) {
            commandText.erase(0, 4);
            std::cout << getSize(&mass) << std::endl;
        }
        else if (commandText.find("PRINT") == 0) {
            commandText.erase(0, 5);
            std::cout << mass << std::endl;
        }
        else if (commandText.find("FIND") == 0) {
            commandText.erase(0, 5);
            try {
                idx = std::stoi(commandText);
                std::cout << getElement(mass, idx) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("IMPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                try {
                    newMass = importMassive(commandText);
                    delete[] mass.data;

                    mass = *newMass;
                    delete newMass;
                }
                catch (const std::exception& e) {
                    std::cout << "Error during import: " << e.what() << std::endl;
                }
            }
        }
        else if (commandText.find("EXPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                exportMassive(mass, commandText);
            }
        }
        break;
    }
    case 'Q': {
        commandText.erase(0, 1);
        if (commandText.find("PUSH") == 0) {
            commandText.erase(0, 5);
            QueuePush(&queue, commandText);
        }
        else if (commandText.find("POP") == 0) {
            commandText.erase(0, 3);
            QueuePop(&queue);
        }
        else if (commandText.find("PRINT") == 0) {
            commandText.erase(0, 5);
            std::cout << queue << std::endl;
        }
        else if (commandText.find("IMPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                try {
                    newQueue = importQueue(commandText);

                    currentq = queue.top;
                    while (currentq != nullptr) {
                        nextq = currentq->next;
                        delete currentq;
                        currentq = nextq;
                    }

                    queue = *newQueue;
                    delete newQueue;
                }
                catch (const std::exception& e) {
                    std::cout << "Error during import: " << e.what() << std::endl;
                }
            }
        }
        else if (commandText.find("EXPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                exportQueue(queue, commandText);
            }
        }
        break;
    }
    case 'S': {
        commandText.erase(0, 1);
        if (commandText.find("PUSH") == 0) {
            commandText.erase(0, 5);
            StackPush(&stack, commandText);
        }
        else if (commandText.find("POP") == 0) {
            commandText.erase(0, 3);
            StackPop(&stack);
        }
        else if (commandText.find("PRINT") == 0) {
            commandText.erase(0, 5);
            std::cout << stack << std::endl;
        }
        else if (commandText.find("IMPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                try {
                    newStack = importStack(commandText);

                    currents = stack.top;
                    while (currents != nullptr) {
                        nexts = currents->next;
                        delete currents;
                        currents = nexts;
                    }

                    stack = *newStack;
                    delete newStack;
                }
                catch (const std::exception& e) {
                    std::cout << "Error during import: " << e.what() << std::endl;
                }
            }
        }
        else if (commandText.find("EXPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                exportStack(stack, commandText);
            }
        }
        break;
    }
    case 'T': {
        commandText.erase(0, 1);
        if (commandText.find("INSERT") == 0) {
            commandText.erase(0, 7);
            try {
                idx = std::stoi(commandText);
                tree.insert(idx);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("REMOVE") == 0) {
            commandText.erase(0, 7);
            try {
                idx = std::stoi(commandText);
                tree.remove(idx);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("FIND") == 0) {
            commandText.erase(0, 5);
            try {
                idx = std::stoi(commandText);
                if (tree.search(idx)) {
                    std::cout << idx << " is in tree\n";
                }else{
                    std::cout << idx << " not found in tree\n";
                }
            }
            catch (const std::invalid_argument& e) {
                std::cout << "incorrect input to command, try using index.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "incorrect input to command, out of range error.\n";
            }
        }
        else if (commandText.find("HEIGHT") == 0) {
            commandText.erase(0, 6);
            std::cout << "Tree height: " << tree.getHeight() << std::endl;
        }
        else if (commandText.find("PRINT") == 0) {
            commandText.erase(0, 5);
            tree.printInorder();
            tree.printPreorder();
        }
        else if (commandText.find("IMPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                try {
                    newTree = importTree(commandText);

                    tree.clear();

                    tree = *newTree;
                    delete newTree;
                }
                catch (const std::exception& e) {
                    std::cout << "Error during import: " << e.what() << std::endl;
                }
            }
        }
        else if (commandText.find("EXPORT") == 0) {
            commandText.erase(0, 7);
            if (commandText.find(".txt") == std::string::npos) {
                std::cout << "incorrect filename, try using .txt in the end of filename.\n";
            }
            else {
                tree.exportTree(commandText);
            }
        }
        break;
    }
    case 'E': {
        std::cout << "End progarmm process\n";
        goto endProgramm;
        break;
    }
    case 'H': {
        std::cout << "COMMAND LIST\n";
        std::cout << "Format: T - container type, TCOMMAND parameter(parameter type)\n";
        std::cout << "MINSERT index(int) value(string)\n";
        std::cout << "MSET index(int) value(string)\n";
        std::cout << "MREMOVE index(int)\n";
        std::cout << "MSIZE\n";
        std::cout << "TINSERT value(int)\n";
        std::cout << "TREMOVE value(int)\n";
        std::cout << "THEIGHT\n";
        std::cout << "(D/F)ADDAFTER search_value(string) value(string)\n";
        std::cout << "(D/F)ADDBEFORE search_value(string) value(string)\n";
        std::cout << "(D/F)PUSHFORWARD value(string)\n";
        std::cout << "(D/F)DELAFTER search_value(string)\n";
        std::cout << "(D/F)DELBEFORE search_value(string)\n";
        std::cout << "(D/F)POPBACK\n";
        std::cout << "(D/F)POPFORWARD\n";
        std::cout << "(D/F)DELKEY value(string)\n";
        std::cout << "(Q/S)PUSH value(string)\n";
        std::cout << "(Q/S)POP\n";
        std::cout << "(D/F/M)PUSHBACK value(string)\n";
        std::cout << "(D/F/M/T)FIND index(int)\n";
        std::cout << "(D/F/M/Q/S/T)PRINT\n";
        std::cout << "(D/F/M/Q/S/T)IMPORT filepath(string)\n";
        std::cout << "(D/F/M/Q/S/T)EXPORT filepath(string)\n";
        std::cout << "H - Help\n";
        std::cout << "E - End programm\n";
        break;
    }
    default:
        std::cout << "Unknown command\n";
        break;
    }
    goto newCommand;
endProgramm:

    return 0;
}

