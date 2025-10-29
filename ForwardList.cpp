#include "ForwardList.h"

Node* GetNode(ForwardList fList, int idx) {
    int nowIdx = 0;
    while (true) {
        if (fList.head == nullptr) {
            return (new Node{ "", nullptr });
        }
        if (nowIdx == idx) {
            return fList.head;
        }
        fList.head = fList.head->next;
        nowIdx++;
    }
}

Node* GetNode(ForwardList fList, std::string key) {
    Node* nowNode = fList.head;
    while (true) {
        if (nowNode->key == key) {
            return nowNode;
        }
        nowNode = nowNode->next;
    }
    return nullptr;
}

void AddNode(ForwardList fList, Node* ptr, std::string key) {
    Node* nowNode = fList.head;
    while(nowNode != nullptr) {
        if (nowNode == ptr) {
            Node* newNode = new Node{ key, ptr->next };
            ptr->next = newNode;
            break;
        }
        nowNode = nowNode->next;
    }
}

void FLPushForward(ForwardList* fList, std::string key) {
    Node* node = new Node{ key, fList->head };
    fList->head = node;
}

void AddNodeBefore(ForwardList* fList, Node* ptr, std::string key) {
    Node* nowNode = fList->head;
    if (nowNode == ptr) {
        FLPushForward(fList, key);
    }
    else {
        while (true) {
            if (nowNode->next == ptr) {
                AddNode(*fList, nowNode, key);
                break;
            }
            nowNode = nowNode->next;
        }
    }
}

void CreateFL(ForwardList* fList, std::string keyBegin) {
    fList->head = new Node{ keyBegin, nullptr };
}

void DeleteNode(ForwardList fList, Node* ptr) {
    Node* nowNode = fList.head;
    while (nowNode != nullptr) {
        if (nowNode == ptr) {
            Node* deleteNode = ptr->next;
            ptr->next = deleteNode->next;
            delete deleteNode;
            break;
        }
        nowNode = nowNode->next;
    }
}

void DeleteNodeBefore(ForwardList* fList, Node* ptr) {
    Node* nowNode = fList->head;
    while (true) {
        if (nowNode->next == nullptr) {
            break;
        }
        if (nowNode->next->next == ptr) {
            DeleteNode(*fList, nowNode);
            break;
        }
        nowNode = nowNode->next;
    }
}

void FLPopBack(ForwardList* fList) {
    DeleteNodeBefore(fList, nullptr);
}

void FLPopForward(ForwardList* fList) {
    Node* deleteNode = fList->head;
    fList->head = deleteNode->next;
    delete deleteNode;
}

void FLPushBack(ForwardList* fList, std::string key) {
    AddNodeBefore(fList, nullptr, key);
}

/*void AddNode(ForwardList* fList, int idx, std::string key) {
    if (idx == 0) {
        FLPushForward(fList, key);
    }
    else {
        AddNode(GetNode(*fList, idx - 1), key);
    }
}
*/
void DeleteNode(ForwardList* fList, std::string key) {
    Node* nowNode = fList->head;
    if (fList->head->key == key) {
        FLPopForward(fList);
    }
    else {
        while (true) {
            if (nowNode->next->key == key) {
                DeleteNode(*fList, nowNode);
                break;
            }
            nowNode = nowNode->next;
        }
    }
}

std::ostream& operator<< (std::ostream& os, ForwardList fList) {
    while (true) {
        if (fList.head->next == nullptr) {
            os << fList.head->key;
            break;
        }
        os << fList.head->key << " ";
        fList.head = fList.head->next;
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, Node* node) {
    os << node->key;
    return os;
}

void exportFL(ForwardList fl, std::string path) {
    std::ofstream out;
    out.open(path);
    if (out.is_open()) {
        out << fl;
    }
    out.close();
}

ForwardList* importFL(std::string path) {
    ForwardList* result = new ForwardList;
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        std::string data;
        in >> data;
        CreateFL(result, data);
        while (in >> data) {
            FLPushBack(result, data);
        }
    }
    in.close();
    return result;
}