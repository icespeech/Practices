#include <iostream>
#include "SolutionClass.h"
using std::cout;

int main()
{
    string start = "talk";
    string end = "tail";
    //char* dictInCStr[] = { "hot", "dot", "dog", "lot", "log" };
    char* dictInCStr[] = { "talk","tons","fall","tail","gale","hall","negs" };
    std::unordered_set<string> dict(&dictInCStr[0], &dictInCStr[7]);
    Solution solution;
    
    cout << solution.ladderLength(start, end, dict);

    int i;
    std::cin >> i; 

    return 0;
}