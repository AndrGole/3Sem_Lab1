#pragma once

#include <iostream>
#include <fstream>

struct Node2 {
    std::string key;
    Node2* next;
    Node2* previous;
};

struct DoubleLinkedList {
    Node2* head;
    Node2* tail;
};

//Node2* nullNode2 = new Node2{ "", nullptr, nullptr };

void AddNode2(DoubleLinkedList* dList, Node2* ptr, std::string key);

void AddNode2Before(DoubleLinkedList* dList, Node2* ptr, std::string key);

void CreateDL(DoubleLinkedList* dList, std::string keyBegin);

void DeleteNode2(DoubleLinkedList* dList, Node2* ptr);

void DeleteNode2Before(DoubleLinkedList* dList, Node2* ptr);

void DLPopBack(DoubleLinkedList* dList);

void DLPopForward(DoubleLinkedList* dList);

void DLPushBack(DoubleLinkedList* dList, std::string key);

void DLPushForward(DoubleLinkedList* dList, std::string key);

Node2* GetNode2(DoubleLinkedList dList, int idx);

Node2* GetNode2(DoubleLinkedList dList, std::string key);

//void AddNode2(DoubleLinkedList* dList, int idx, std::string key);

void DeleteNode2(DoubleLinkedList* dList, std::string key);

std::ostream& operator<< (std::ostream& os, DoubleLinkedList dList);

std::ostream& operator<< (std::ostream& os, Node2* node);

void exportDL(DoubleLinkedList dl, std::string path);

DoubleLinkedList* importDL(std::string path);