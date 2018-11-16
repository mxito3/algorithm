#include "iostream"
#include <vector>
#include "string.h"
using namespace std;
// string stringList[100];
// string tempList[100];
class order
{
public:
    void createArrange(int nowPosition);
    order(std::vector<string> tempStringList, string result);
    std::vector<string> stringList;
    std::vector<string> tempList;
    bool whetherCan;  //存储是不是找到了
    int depth;
    string result;  //需要的结果
    // order()
};




order::order(std::vector<string> tempStringList, string result)
{
    this->depth = tempStringList.size();
    this->result = result;
    // cout<<this->depth;
    this->stringList = vector<string>(this->depth);
    this->tempList = std::vector<string>(this->depth);
    this->stringList = tempStringList;
    this->whetherCan = false;
}


void order::createArrange(int nowPosition)  //抽象成往盒子里放卡片，最初在第０个箱子
{
    //判断是不是满足条件
    string temp;
    for (int i = 0; i < nowPosition; i++)
    {
        temp += this->tempList[i];
    }

    //满足条件
    if (temp == result)
    {
        this->whetherCan = true;
        return;
    }
    //走到最后一个格子还没有找到，返回
    if (nowPosition == this->depth)
    {
        return;
    }
    for (int i = 0; i < depth; i++)
    {
        this->tempList[nowPosition] = this->stringList[i];
        createArrange(nowPosition + 1);
    }
    return ;

}

int main()
{
    string s="[i love byte dance]";
    string result="ilovebytedance";
    int pos = s.find(']');
    if (pos > -1)
    {
        s.erase(pos);
    }
    std::vector<string> temp;
    char *p = strtok(&s[1u], " ");  //string 转char *  传1u直接删除了[
    while (p)
    {
        temp.push_back(p);
        p = strtok(NULL, " ");
    }

    //创建实例
    order *test = new order(temp, result);
    test->createArrange(0);
    if (test->whetherCan)
    {
        cout << "存在";
    }
    else
    {
        cout << "不存在";
    }
}