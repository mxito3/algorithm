#include "iostream"
#include <vector>
using namespace std;
void search(vector<int> array,int num,int left,int right)
{
    if(right<=left+1)  //right=left+1是最后一步,<为了兼容长度为1的数组
    {
        cout<<"没找到";
        return;
    }
    int mid=(left+right)/2;
    if(num==array[mid])
        cout<<"找到了,是第 "<<mid<<"  个 "<<endl;
    else if(num<array[mid])
        return search(array,num,left,mid);
    else if(num>array[mid])
        return search(array,num,mid,right);

}
int main()
{
    vector<int> test;
    for(int i=0;i<5;i++)
    {
        test.push_back(i);
    }
    //test.push_back(2);
    search(test,2,0,test.size()-1);
}
