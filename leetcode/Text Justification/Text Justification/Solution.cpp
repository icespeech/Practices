#include "Solution.h"
using std::vector;
using std::string;

string justify(vector<string> words, int maxWidth)
{
    vector<char> ret;

    if (words.size() == 1)
    {
        ret.insert(ret.end(), words[0].begin(), words[0].end());
        for (int i = words[0].size(); i < maxWidth; ++i)
            ret.push_back(' ');

        return string(ret.begin(), ret.end());
    }

    int spaces = maxWidth;
    int eachspace, remainSpaces;

    for (const string& s : words)
        spaces -= s.size();
    
    eachspace = spaces / (words.size()-1);
    remainSpaces = spaces % (words.size()-1);

    for (int i = 0; i < words.size() - 1; ++i)
    {
        ret.insert(ret.end(), words[i].begin(), words[i].end());
        for (int i = 0; i < eachspace; ++i)
            ret.push_back(' ');

        if (remainSpaces > 0)
        {
            ret.push_back(' ');
            --remainSpaces;
        }
    }

    ret.insert(ret.end(), words[words.size() - 1].begin(), words[words.size() - 1].end());
    return string(ret.begin(), ret.end());
}

vector<string> Solution::fullJustify(vector<string>& words, int maxWidth)
{
    if (words.size() == 0) return vector<string>();

    vector<string> ret;
    vector<string> tmpLayer;

    if (maxWidth == 0)
    {
        for (const string& s : words)
        {
            ret.push_back("");
        }
        return ret;
    }

    int currentLength = 0;
    for (const string& s : words)
    {
        // if s.size() is zero, the later judgement condition will not be satisfied
        if (currentLength == maxWidth || (currentLength + s.size()) > maxWidth)
        {
            ret.push_back(justify(tmpLayer, maxWidth));
            tmpLayer.clear();
            currentLength = 0;
        }

        tmpLayer.push_back(s);
        currentLength += s.size();
        if (currentLength < maxWidth)
            // reserve for the next space
            ++currentLength;
    }

    string lastLine;
    for (const string& s : tmpLayer)
    {
        lastLine += s;
        if (lastLine.size() < maxWidth)
            lastLine += " ";
    }
    
    for (int i = lastLine.size(); i < maxWidth; ++i)
        lastLine += " ";

    ret.push_back(lastLine);
    return ret;
}