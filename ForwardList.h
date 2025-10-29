#pragma once

#include <iostream>
#include <fstream>

struct Node {
    std::string key;
    Node* next;
};

struct ForwardList {
    Node* head;
};

//Node* nullNode = new Node{ "", nullptr };

void CreateFL(ForwardList* fList, std::string keyBegin);

void AddNode(ForwardList fList, Node* ptr, std::string key);

void AddNodeBefore(ForwardList* flist, Node* ptr, std::string key);

void FLPushBack(ForwardList* fList, std::string key);

void FLPushForward(ForwardList* fList, std::string key);

void DeleteNode(ForwardList fList, Node* ptr);

void DeleteNodeBefore(ForwardList* fList, Node* ptr);

void FLPopBack(ForwardList* fList);

void FLPopForward(ForwardList* fList);

Node* GetNode(ForwardList fList, int idx);

Node* GetNode(ForwardList fList, std::string key);

//void AddNode(ForwardList* fList, int idx, std::string key);

void DeleteNode(ForwardList* fList, std::string key);

std::ostream& operator<< (std::ostream& os, ForwardList fList);

std::ostream& operator<< (std::ostream& os, Node* node);

void exportFL(ForwardList fl, std::string path);

ForwardList* importFL(std::string path);