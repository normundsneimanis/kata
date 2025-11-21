#include <iostream>
using std::cout;
using std::endl;
using std::swap;

class List {
    std::size_t current = 0;
    std::size_t size = 2;
    int* list{ new int[size]{} };
    bool doPrint = false;
public:
    List() {
        cout << "Constructing List" << endl;
    };

    void enablePrint() {
        doPrint = true;
    }

    void add(const int element) {
        if (this->current == size) {
            if (doPrint)
                cout << "Resizing list from " << size << " to " << size * 2 << endl;
            size *= 2;
            int* newlist{ new int[size]{} };
            for (auto i = 0; i < current; i++) {
                newlist[i] = list[i];
            }
            delete[] list;
            list = newlist;
        }
        list[current++] = element;
    }

    void print() const {
        if (doPrint) {
            std::cout << "Number of elements: " << current << std::endl;
            for (auto i = 0; i < current; i++) {
                std::cout << "Element " << i << ": " << list[i] << std::endl;
            }
        }
    }

    ~List() {
        std::cout << "Deallocating memory" << std::endl;
        current = 0;
        size = 0;
        delete[] list;
    }
};

template  <typename T>
class BSTNode {
public:
    T value = 0;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;

    explicit BSTNode(T val) {
        value = val;
    }

    ~BSTNode() {
        cout << "Removing node " << value << std::endl;
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};

template  <typename T>
class BST {
    BSTNode<T> * root = nullptr;

    void addr(BSTNode<T>** selected_root, T value) {
        if (*selected_root == nullptr) {
            *selected_root = new BSTNode(value);
        } else if (value < (*selected_root)->value) {
            addr(&(*selected_root)->left, value);
        } else if (value > (*selected_root)->value) {
            addr(&(*selected_root)->right, value);
        }
    }

    void preordinalr(BSTNode<T>** selected_root) {
        if (*selected_root == nullptr)
            return;
        if ((*selected_root)->left != nullptr) {
            preordinalr(&(*selected_root)->left);
        }
        cout << (*selected_root)->value << " ";
        if ((*selected_root)->right != nullptr) {
            preordinalr(&(*selected_root)->right);
        }
    }

    BSTNode<T>* get_inorder(BSTNode<T>** selected_root) {
        if ((*selected_root)->left != nullptr) {
            return get_inorder(&(*selected_root)->left);
        }
        return *selected_root;
    }

    void remove_recurse(BSTNode<T>** selected_root, T value) {
        if (!(selected_root == nullptr))
            cout << "Recursively removing " << value << " at " << (*selected_root)->value << endl;
        if (*selected_root == nullptr) {
        } else if (value < (*selected_root)->value) {
            remove_recurse(&(*selected_root)->left, value);
        } else if (value > (*selected_root)->value) {
            remove_recurse(&(*selected_root)->right, value);
        } else if (value == (*selected_root)->value) {
            if ((*selected_root)->right == nullptr && (*selected_root)->left == nullptr) {
                delete *selected_root;  // Explicitly delete the node
                *selected_root = nullptr; // Set parent pointer to null
            } else if ((*selected_root)->right == nullptr && (*selected_root)->left != nullptr) {
                BSTNode<T> * current = *selected_root;
                *selected_root = (*selected_root)->left;
                delete current;
            } else if ((*selected_root)->right != nullptr && (*selected_root)->left == nullptr) {
                BSTNode<T> * current = *selected_root;
                *selected_root = (*selected_root)->right;
                delete current;
            } else if ((*selected_root)->right != nullptr && (*selected_root)->left != nullptr) {
                BSTNode<T>* successor = get_inorder(&(*selected_root)->right);
                cout << "Replacing " << (*selected_root)->value << " with " << successor->value << endl;
                (*selected_root)->value = successor->value;
                remove_recurse(&(*selected_root)->right, successor->value);
            }
        }
    }

public:
    void add(T value) {
        addr(&root, value);
    }

    void preordinal() {
        preordinalr(&root);
        std::cout << std::endl;
    }

    void remove(T value) {
        remove_recurse(&root, value);
    }

    ~BST() {
        cout << "Removing BST root " << endl;
        delete root;

    }
};


int main() {
    BST<int> tree;
    tree.add(5);
    tree.add(100);
    tree.add(3);
    tree.add(1);
    tree.add(10);
    tree.add(8);
    tree.add(6);
    tree.add(5);
    tree.add(7);
    tree.add(9);
    tree.add(11);
    tree.preordinal();
    tree.remove(8);
    tree.preordinal();

    // {
    //     List a;
    //     a.enablePrint();
    //     a.add(1);
    //     a.add(2);
    //     a.add(3);
    //     a.add(4);
    //     a.add(5);
    //     a.print();
    // }
    //
    // {
    //     List* b = new List();
    //     b->enablePrint();
    //     b->add(10);
    //     b->add(11);
    //     b->add(12);
    //     b->add(13);
    //     b->add(14);
    //     b->add(15);
    //     b->print();
    //     delete b;
    // }
    return 0;
}
