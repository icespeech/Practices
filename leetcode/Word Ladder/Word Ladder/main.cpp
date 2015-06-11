#include <iostream>
#include "SolutionClass.h"
using std::cout;

int main()
{
    string start = "hit";
    string end = "lot";
    char* dictInCStr[] = { "hot", "dot", "dog", "lot", "log" };
    unordered_set<string> dict(&dictInCStr[0], &dictInCStr[4]);
    Solution solution;
    
    cout << solution.ladderLength(start, end, dict);

    int i;
    std::cin >> i; 

    return 0;
}