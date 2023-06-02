// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <iostream>

class Tree {
 private:
    std::vector<Tree*> root;
    char symb;
    explicit Tree(char ch) : symb(ch) {}
    void createNode(const std::vector<char>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            std::vector<char> tmp = vec;
            root.push_back(new Tree(tmp[i]));
            tmp.erase(tmp.begin() + i);
            root[i]->createNode(tmp);
        }
    }

 public:
    explicit Tree(const std::vector<char>& vec) {
        symb = '*';
        createNode(vec);
    }
    int getSize() const {
        return root.size();
    }
    char getSymb() const {
        return symb;
    }
    Tree& operator[](int n) const {
        return *root[n];
    }
};
#endif  // INCLUDE_TREE_H_
