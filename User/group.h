#ifndef GROUPO_H
#define GROUP_H
#include "groupuser.h"
#include <string>
#include <vector>

using namespace std;
class Group
{
public:
    Group(int id, string name, string desc);
    void setGroupId(int groupId);
    void setGroupName(string groupName);
    void setGroupoDesc(string desc);
    int getGroupId();
    string getGroupDesc();
    string getGroupName();
    vector<GroupUser> getUser();
    Group();
    ~Group();

private:
    /* data */
    int groupId;
    string groupName;
    string desc;
    vector<GroupUser> user;//群组成员
};


#endif
