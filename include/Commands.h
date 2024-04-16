#pragma once
#include <unordered_map>

std::unordered_map<std::string, int> commands ={
    {"cre", 0}, {"en", 1}, {"red", 2}, {"draw", 3}, {"dup", 4},
    {"stack", 5}, {"del", 6}, {"help", 7}, {"exit", 8}
};

enum cmdLst{cre, en, red, dra, dup, sta, del, hel, ex};
