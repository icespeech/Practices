#include "Solution.h"

#define course_num first
#define course_item second
#define in_level first
#define nexts second

#include <list>
#include <set>
#include <unordered_map>
#include <queue>
using std::vector;
using std::pair;

vector<int> Solution::findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    if (numCourses == 0) return vector<int>();

    vector<int> ret;
    // course number, course in-level, next courses
    std::unordered_map<int, pair<int, vector<int>>> courses;
    std::set<int> firstTimeElements;
    std::queue<int> toBeTaken;
    
    // list of prerequisites
    std::list<pair<int, int>> lp(prerequisites.begin(), prerequisites.end());
    for (auto course_chain : lp)
    {
        int former_course = course_chain.second, later_course = course_chain.first;

        if (courses.find(former_course) == courses.end())
        {
            courses[former_course].in_level = 0;
            courses[former_course].nexts.push_back(later_course);
            firstTimeElements.insert(former_course);
        }
        else courses[former_course].nexts.push_back(later_course);

        if (courses.find(later_course) == courses.end())
            courses[later_course].in_level = 1;
        else
            ++courses[later_course].in_level;

        // the later course had dependancies, it's impossible to be a first time taken course
        firstTimeElements.erase(later_course);
    }

    std::set<int> remaining_courses;
    for (int i = 0; i < numCourses; ++i)
        remaining_courses.insert(i);

    for (auto fte : firstTimeElements)
    {
        ret.push_back(fte);
        for (int next_course : courses[fte].nexts)
        {
            --courses[next_course].in_level;
            if (courses[next_course].in_level == 0)
                toBeTaken.push(next_course);
        }
        courses.erase(fte);
        remaining_courses.erase(fte);
    }

    while (toBeTaken.size() > 0)
    {
        int toBeTakenCourse = toBeTaken.front();

        ret.push_back(toBeTakenCourse);
        for (int i : courses[toBeTakenCourse].nexts)
        {
            --courses[i].in_level;
            if (courses[i].in_level == 0)
                toBeTaken.push(i);
        }
        courses.erase(toBeTakenCourse);
        toBeTaken.pop();

        remaining_courses.erase(toBeTakenCourse);
    }
    if (courses.size() != 0)
        return vector<int>();
    
    auto it = remaining_courses.begin();
    for (int i = ret.size(); i < numCourses; ++i)
        ret.push_back(*it++);

    return ret;
}