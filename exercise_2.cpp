#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

// int main() {
    //1.	Create a binary Tree
    //2.	Randomly generate 50 numbers
    //3.	Insert each number into the tree
    //4.    Print a tree result
    //5.    Challenge: Implement a function that returns the height of the tree

int main() {

    BinaryTree tree;


    tree.generateTree();


    std::cout << "Binary Tree:" << std::endl;
    tree.printTree();

    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;

    return 0;
}


