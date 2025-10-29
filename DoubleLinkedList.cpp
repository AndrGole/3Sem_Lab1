#include "DoubleLinkedList.h"

void AddNode2(DoubleLinkedList* dList, Node2* ptr, std::string key) {
    Node2* nowNode = dList->head;
    while (nowNode != nullptr) {
        if (nowNode == ptr) {
            Node2* newNode = new Node2{ key, ptr->next, ptr };
            if (newNode->next != nullptr) {
                newNode->next->previous = newNode;
            }
            else {
                dList->tail = newNode;
            }
            ptr->next = newNode;
            break;
        }
        nowNode = nowNode->next;
    }
}

void AddNode2Before(DoubleLinkedList* dList, Node2* ptr, std::string key) {
    Node2* nowNode = dList->head;
    while (nowNode != nullptr) {
        if (nowNode == ptr) {
            Node2* newNode = new Node2{ key, ptr, ptr->previous };
            if (newNode->previous != nullptr) {
                newNode->previous->next = newNode;
            }
            else {
                dList->head = newNode;
            }
            ptr->previous = newNode;
            break;
        }
        nowNode = nowNode->next;
    }
}

void CreateDL(DoubleLinkedList* dList, std::string keyBegin) {
    dList->head = new Node2{ keyBegin, nullptr, nullptr };
    dList->tail = dList->head;
}

void DeleteNode2(DoubleLinkedList* dList, Node2* ptr) {
    Node2* nowNode = dList->head;
    while (nowNode != nullptr) {
        if (nowNode == ptr) {
            Node2* deleteNode = ptr->next;
            ptr->next = deleteNode->next;
            if (deleteNode->next != nullptr) {
                deleteNode->next->previous = ptr;
            }
            else {
                dList->tail = deleteNode->previous;
            }
            delete deleteNode;
            break;
        }
        nowNode = nowNode->next;
    }
}

void DeleteNode2Before(DoubleLinkedList* dList, Node2* ptr) {
    Node2* nowNode = dList->head;
    while (nowNode != nullptr) {
        if (nowNode == ptr) {
            Node2* deleteNode = ptr->previous;
            ptr->previous = deleteNode->previous;
            if (deleteNode->previous != nullptr) {
                deleteNode->previous->next = ptr;
            }
            else {
                dList->head = deleteNode->next;
            }
            delete deleteNode;
            break;
        }
        nowNode = nowNode->next;
    }
}

void DLPopBack(DoubleLinkedList* dList) {
    Node2* deleteNode = dList->tail;
    dList->tail = deleteNode->previous;
    deleteNode->next = nullptr;
    delete deleteNode;
}

void DLPopForward(DoubleLinkedList* dList) {
    Node2* deleteNode = dList->head;
    dList->head = deleteNode->next;
    deleteNode->previous = nullptr;
    delete deleteNode;
}

void DLPushBack(DoubleLinkedList* dList, std::string key) {
    Node2* nowNode = dList->tail;
    AddNode2(dList, nowNode, key);
    dList->tail = nowNode->next;
}

void DLPushForward(DoubleLinkedList* dList, std::string key) {
    Node2* node = new Node2{ key, dList->head, nullptr };
    dList->head = node;
    node->next->previous = node;
}

Node2* GetNode2(DoubleLinkedList dList, int idx) {
    int nowIdx = 0;
    while (true) {
        if (dList.head == nullptr) {
            return (new Node2{ "", nullptr, nullptr });
        }
        if (nowIdx == idx) {
            return dList.head;
        }
        dList.head = dList.head->next;
        nowIdx++;
    }
}
/*
void AddNode2(DoubleLinkedList* dList, int idx, std::string key) {
    if (idx == 0) {
        DLPushForward(dList, key);
    }
    else {
        AddNode2(dList, GetNode2(*dList, idx - 1), key);
    }
}
*/
void DeleteNode2(DoubleLinkedList* dList, std::string key) {
    if (dList->head->key == key) {
        DLPopForward(dList);
    }
    else if (dList->tail->key == key) {
        DLPopBack(dList);
    }
    else {
        Node2* nowNode = dList->head;
        while (true) {
            if (nowNode->next->key == key) {
                DeleteNode2(dList, nowNode);
            }
            nowNode = nowNode->next;
        }
    }
}

std::ostream& operator<< (std::ostream& os, DoubleLinkedList dList) {
    while (true) {
        if (dList.head->next == nullptr) {
            os << dList.head->key;
            break;
        }
        os << dList.head->key << " ";
        dList.head = dList.head->next;
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, Node2* node) {
    os << node->key;
    return os;
}

void exportDL(DoubleLinkedList dl, std::string path) {
    std::ofstream out;
    out.open(path);
    if (out.is_open()) {
        out << dl;
    }
    out.close();
}

DoubleLinkedList* importDL(std::string path) {
    DoubleLinkedList* result = new DoubleLinkedList;
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        std::string data;
        in >> data;
        CreateDL(result, data);
        while (in >> data) {
            DLPushBack(result, data);
        }
    }
    in.close();
    return result;
}

Node2* GetNode2(DoubleLinkedList dList, std::string key) {
    Node2* nowNode = dList.head;
    while (true) {
        if (nowNode->key == key) {
            return nowNode;
        }
        nowNode = nowNode->next;
    }
    return nullptr;
}