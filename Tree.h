#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// ���� AVL ������
class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k);
};

class AVLTree {
private:
    AVLNode* root;

    // �������� ������ ����
    int getHeight(AVLNode* node);

    // �������� ������-������ ����
    int getBalance(AVLNode* node);

    // ������ �������
    AVLNode* rightRotate(AVLNode* y);

    // ����� �������
    AVLNode* leftRotate(AVLNode* x);

    // ����������� �������
    AVLNode* insert(AVLNode* node, int key);

    // ����� ���� � ����������� ������
    AVLNode* minValueNode(AVLNode* node);

    // ����������� ��������
    AVLNode* deleteNode(AVLNode* root, int key);

    // ����� inorder (������������� �����)
    void inorder(AVLNode* node);

    // ����� preorder
    std::string preorder(AVLNode* node);

    // ����� ��������
    bool search(AVLNode* node, int key);

    // ����������� ����������� ������
    AVLNode* copyTree(AVLNode* node);

    // ����������� �������� ������  
    void clearTree(AVLNode* node);

public:
    AVLTree();

    AVLTree(const AVLTree& other);

    ~AVLTree();

    AVLTree& operator=(const AVLTree& other);

    // ��������� ������
    void insert(int key);

    void remove(int key);

    bool search(int key);

    void printInorder();

    void printPreorder();

    int getHeight();

    void exportTree(std::string path);

    void clear();
};

AVLTree* importTree(std::string path);