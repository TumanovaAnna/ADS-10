// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
    if (n <= 1) return 1;
    return fact(n - 1) * n;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    if (tree.getSize() == 0 || n > fact(tree.getSize()))
        return {};

    if (tree.getSymb() == '*')
        n=n-1;

    std::vector<char> res;
    int temp = fact(tree.getSize() - 1);
    res.push_back(tree[n / temp].getSymb());
    std::vector<char> n2 = getPerm(tree[n / temp], n % temp);
    res.insert(res.end(), n2.begin(), n2.end());

    return res;
}
