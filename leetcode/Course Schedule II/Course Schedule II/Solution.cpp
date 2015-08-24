#define _SCL_SECURE_NO_WARNINGS

#include "Solution.h"
#include <algorithm>
#include <list>
#include <set>
#include <queue>
using std::vector;
using std::pair;

class courseItem
{
public:
    courseItem(int c, int i) :
        courseNum(c),
        inLevel(i)
    {};
    int courseNum;
    int inLevel;
    std::list<courseItem*> nexts;
};

vector<int> Solution::findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    if (numCourses == 0) return vector<int>();

    vector<int> ret;
    courseItem** courses = new courseItem*[numCourses];
    std::fill_n(courses, numCourses, nullptr);

    std::set<courseItem*> firstTimeElements;
    std::queue<courseItem*> toBeTaken;

    // list of prerequisites
    std::list<pair<int, int>> lp(prerequisites.begin(), prerequisites.end());
    for (auto course_chain : lp)
    {
        int former_course = course_chain.second, later_course = course_chain.first;

        if (courses[former_course] == nullptr)
        {
            courses[former_course] = new courseItem(former_course, 0);
            firstTimeElements.insert(courses[former_course]);
        }

        if (courses[later_course] == nullptr)
            courses[later_course] = new courseItem(later_course, 1);
        else
            ++courses[later_course]->inLevel;

        courses[former_course]->nexts.push_back(courses[later_course]);
        firstTimeElements.erase(courses[later_course]);
    }

    for (auto e : firstTimeElements)
        toBeTaken.push(e);

    while (toBeTaken.size() > 0)
    {
        int toBeTakenCourse = toBeTaken.front()->courseNum;

        ret.push_back(toBeTakenCourse);
        for (auto n : courses[toBeTakenCourse]->nexts)
        {
            int nextCourse = n->courseNum;
            --courses[nextCourse]->inLevel;
            if (courses[nextCourse]->inLevel == 0)
                toBeTaken.push(courses[nextCourse]);
        }
        toBeTaken.pop();
    }

    bool circle = false;
    for (int i = 0; i < numCourses; ++i)
    {
        if (courses[i] == nullptr)
            ret.push_back(i);
        else
        {
            if (courses[i]->inLevel != 0)
                circle = true;
            delete courses[i];
        }
    }

    delete[] courses;
    if (circle)
        return vector<int>();

    return ret;
}