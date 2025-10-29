#include "Tree.h"

AVLNode::AVLNode(int k) {
    key = k;
    left = right = nullptr;
    height = 1;
}

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::getHeight() {
    return getHeight(root);
}

int AVLTree::getBalance(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Выполняем поворот
    x->right = y;
    y->left = T2;

    // Обновляем высоты
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Выполняем поворот
    y->left = x;
    x->right = T2;

    // Обновляем высоты
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (node == nullptr) {
        return new AVLNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        // Дубликаты не разрешены
        return node;
    }

    // 1. Обновляем высоту текущего узла
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 2. Получаем баланс-фактор
    int balance = getBalance(node);

    // 3. Если узел несбалансирован, есть 4 случая

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Если сбалансирован, возвращаем неизмененный узел
    return node;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

AVLNode* AVLTree::deleteNode(AVLNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Узел для удаления найден

        // Узел с одним или без потомков
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = root->left ? root->left : root->right;

            // Нет потомков
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                // Один потомок
                *root = *temp;
            }
            delete temp;
        }
        else {
            // Узел с двумя потомками
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Если дерево стало пустым
    if (root == nullptr) return root;

    // 1. Обновляем высоту
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 2. Получаем баланс-фактор
    int balance = getBalance(root);

    // 3. Балансировка

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVLTree::remove(int key) {
    root = deleteNode(root, key);
}

void AVLTree::inorder(AVLNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

void AVLTree::printInorder() {
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}

std::string AVLTree::preorder(AVLNode* node) {
    std::string result;
    if (node != nullptr) {
        //cout << node->key << " ";
        if (node == root) {
            result = std::to_string(node->key);
        }
        else {
            result = " " + std::to_string(node->key);
        }
        result = result + preorder(node->left);
        result = result + preorder(node->right);
        return result;
    }
    else {
        return "";
    }
}

void AVLTree::printPreorder() {
    cout << "Preorder: ";
    cout << preorder(root);
    cout << endl;
}

bool AVLTree::search(AVLNode* node, int key) {
    if (node == nullptr) return false;
    if (node->key == key) return true;
    if (key < node->key) return search(node->left, key);
    return search(node->right, key);
}

bool AVLTree::search(int key) {
    return search(root, key);
}


void AVLTree::exportTree(std::string path) {
    std::ofstream out;
    out.open(path);
    std::string data = preorder(root);
    if (out.is_open()) {
        out << data;
    }
    out.close();
}

AVLTree* importTree(std::string path) {
    AVLTree* result = new AVLTree;
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        int data;
        while (in >> data) {
            result->insert(data);
        }
    }
    in.close();
    return result;
}

AVLTree::AVLTree(const AVLTree& other) {
    root = copyTree(other.root);
}

AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this != &other) {
        clearTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

AVLTree::~AVLTree() {
    clearTree(root);
}

AVLNode* AVLTree::copyTree(AVLNode* node) {
    if (node == nullptr) return nullptr;

    AVLNode* newNode = new AVLNode(node->key);
    newNode->height = node->height;
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}

void AVLTree::clearTree(AVLNode* node) {
    if (node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

void AVLTree::clear() {
    clearTree(root);
    root = nullptr;
}