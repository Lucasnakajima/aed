#include "funHashingProblem.h"
#include <unordered_set>

FunHashingProblem::FunHashingProblem() {}

// -------------------------------------

// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    unordered_set<int> s;
    vector<int> res;
    for(int i=0; i<values.size(); i++){
        if(s.find(values[i]) != s.end())
            res.push_back(values[i]);

        s.insert(values[i]);
        if(i>=k)
            s.erase(values[i-k]);
    }
    return res;
}