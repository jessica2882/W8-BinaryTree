#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include "Node.h"

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree(int value) {
        root = new Node(value);
    }
    void insertLeft(int value) {
        root->left = new Node(value);
    }
    void insertRight(int value) {
        root->right = new Node(value);
    }
    std::string inOrderTraverse() {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    std::string preOrderTraverse() {
        std::string result = "";
        preOrder(root, result);
        return result;
    }
    std::string postOrderTraverse() {
        std::string result = "";
        postOrder(root, result);
        return result;
    }

    Node* getroot() {
        return root;
    }

private:
         void inOrder(Node* node, std::string& result) {
        if (node == nullptr) return;
        inOrder(node->left, result);
        result += std::to_string(node->data) + " ";  
        inOrder(node->right, result);
    }
    void preOrder(Node* node, std::string& result) {
        if (node == nullptr) return;
        result += std::to_string(node->data) + " ";  
        preOrder(node->left, result);
        preOrder(node->right, result);  
    }
    void postOrder(Node* node, std::string& result) {
        if (node == nullptr) return;
        postOrder(node->left, result);
        postOrder(node->right, result);
        result += std::to_string(node->data) + " ";  
    }


//exercise 2
//random value
    bool generateRandomDirection() {
        return rand() % 2 == 0;
    }
//insert value
    void insertValueOn(Node* node, int value) {
        bool direction = generateRandomDirection();
        if (direction) { 
            if (node->left) {
                insertValueOn(node->left, value);
            } else {
                node->left = new Node(value);
            }
        } else {
            if (node->right) {
                insertValueOn(node->right, value);
            } else {
                node->right = new Node(value);
            }
        }
    }
//print value of tree
    void printTree(Node* node, int level) {
        if (node == nullptr) return;
        printTree(node->right, level ); 
        std::cout << std::string(level, ' ') << node->data << std::endl; 
        printTree(node->left, level); 
    }
//height of tree 
    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

public:

    BinaryTree() : root(nullptr) {}

    void generateTree() {

        root = new Node(rand() % 100);

        for (int i = 1; i <= 50; ++i) { 
            insertValueOn(root, rand() % 100);
        }
    }
    void printTree() {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }
        printTree(root, 0);
    }
    int getHeight() {
        return calculateHeight(root);
    }
};

#endif // BINARYTREE_H
