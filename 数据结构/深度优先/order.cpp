//给定一个数n，求１-n 的全排列
#include "iostream"
#include <vector>
using namespace std;
int n[10],book[10];   //n存每一位
#define  depth 3  //小于几的全排序
class order
{
    public:
        void createArrange(int m);
};
void order::createArrange(int m) //抽象成往盒子里放卡片，现在在第m个盒子
{
    //cout<<m;
    if(m==depth+1)
    {
        //cout<<"完了";
        for(int i=1;i<=depth;i++)
        {
            cout<<n[i]<<"    ";
        }
        cout<<endl;
        return;
    }
    else
    {
        for(int i=1;i<=depth;i++) //尝试，
        {
            if(!book[i])  //第i个卡片还没被用
            {
                n[m]=i;
                book[i]=1;
                createArrange(m+1);   //走到第m+1个盒子旁边，往里面放卡片
                book[i]=0; //收回
            }
        }
        return;
    }
}

int main()
{
    order* test=new order();
    test->createArrange(1);
}
