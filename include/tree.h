// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
class Tree {
 private:
    std::vector<Tree*> root;
    char smb;
    explicit Tree(char n1) : smb(n1) {}
    void createNode(const std::vector<char>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            std::vector<char> temp = vec;
            root.push_back(new Tree(temp[i]));
            temp.erase(temp.begin() + i);
            root[i]->createNode(temp);
        }
    }

public:
    explicit Tree(const std::vector<char>& vec) {
        smb = '*';
        createNode(vec);
    }

    int getSize() const {
        return root.size();
    }
    char getSymb() const {
        return smb;
    }
    Tree& operator[](int n) const {
        return *root[n];
    }
};
#endif  // INCLUDE_TREE_H_
