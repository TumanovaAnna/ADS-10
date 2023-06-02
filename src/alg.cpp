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
    std::vector<char> result;
    int tmp = fact(tree.getSize() - 1);

    result.push_back(tree[n / tmp].getSymb());
    std::vector<char> a = getPerm(tree[n / tmp], n % tmp);
    result.insert(result.end(), a.begin(), a.end());

    return result;
}
