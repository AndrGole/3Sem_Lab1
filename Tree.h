#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// Узел AVL дерева
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

    // Получить высоту узла
    int getHeight(AVLNode* node);

    // Получить баланс-фактор узла
    int getBalance(AVLNode* node);

    // Правый поворот
    AVLNode* rightRotate(AVLNode* y);

    // Левый поворот
    AVLNode* leftRotate(AVLNode* x);

    // Рекурсивная вставка
    AVLNode* insert(AVLNode* node, int key);

    // Найти узел с минимальным ключом
    AVLNode* minValueNode(AVLNode* node);

    // Рекурсивное удаление
    AVLNode* deleteNode(AVLNode* root, int key);

    // Обход inorder (сортированный вывод)
    void inorder(AVLNode* node);

    // Обход preorder
    std::string preorder(AVLNode* node);

    // Поиск элемента
    bool search(AVLNode* node, int key);

    // Рекурсивное копирование дерева
    AVLNode* copyTree(AVLNode* node);

    // Рекурсивное удаление дерева  
    void clearTree(AVLNode* node);

public:
    AVLTree();

    AVLTree(const AVLTree& other);

    ~AVLTree();

    AVLTree& operator=(const AVLTree& other);

    // Публичные методы
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