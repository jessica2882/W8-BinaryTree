#include<iostream>
#include <string>

struct Node {
    bool isFolder;
    std::string name;    
    Node* left;           
    Node* right;          

    Node(bool isFolder, std::string name)
        : isFolder(isFolder), name(name), left(nullptr), right(nullptr) {}
};

bool hasNoEmptyFolders(Node* root) {
    if (root == nullptr) return true; 

    if (root->isFolder) {
 
        if (root->left == nullptr && root->right == nullptr) return false;
        return hasNoEmptyFolders(root->left) && hasNoEmptyFolders(root->right);
    }

    return true; 
}

int main() {
    Node* root = new Node(true, "Root");
    Node* folder1 = new Node(true, "Folder1");
    Node* folder2 = new Node(true, "Folder2");
    Node* file1 = new Node(false, "File1");

    root->left = folder1;   
    root->right = folder2;    
    folder1->left = file1;   

    if (hasNoEmptyFolders(root)) {
        std::cout << "All folders are empty!" << std::endl;
    } else {
        std::cout << "There is an empty folder." << std::endl;
    }
    return 0;
}

    

