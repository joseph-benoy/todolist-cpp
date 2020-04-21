#ifndef ITEM_H
#define ITEM_H

#endif // ITEM_H

#include<QString>
#include<string>
using namespace std;
class task
{
public:
    string  name;
    string flag;
    task(){}
    task(string name,string flag)
    {
        this->name = name;
        this->flag = flag;
    }
};
