#ifndef CSR_H
#define CSR_H

#include <vector>
#include <map>
#include <utility>

using namespace std;

struct CSR
{
    vector<int> offset;
    vector<int> intermediate;
    vector<int> property;
};

CSR calculateCSR(
    int vertices,
    const map<int, vector<pair<int, int>>>& graph
);

void printArray(const vector<int>& arr);

#endif