#include "iostream"
#include "stdlib.h"
#include <vector>
using namespace std;
typedef struct nod //节点定义
{
    int num;
    struct nod * left;
    struct nod * right;
}node;
class tree
{
    public:
        void create(node *nowNode,int type);
        void preOrderList(node *head);
        static vector<node *> nodeNeedDelete;  //存储需要释放的内存的地址，析构函数释放，避免内存泄露
        ~tree();
};
vector<node *> tree::nodeNeedDelete;
void tree::create(node *nowNode,int type)  //给当前节点建立左右子树    type=1创建左子树，type=2创建右子树
{
    //读取输入
    int a;
    cin>>a;
    if (a!=0) //0是结束标志
    {
        node * temp= (node *)malloc(sizeof(node));　//在堆上申请内存，自行释放
        this->nodeNeedDelete.push_back(temp);
        temp->num=a;
        temp->left=NULL;
        temp->right=NULL;
        if(type==1)
        {
           nowNode->left=temp;
        }
        else
        {
            nowNode->right=temp;
        }
        create(temp,1);
        create(temp,2);
        //free(temp);
    }
    cout<<endl;
    //<F5>free newNode;
}

void tree::preOrderList(node *head)　//先序遍历
{

    if(head)
    {
        cout<<head->num<<"    ";
        preOrderList(head->left);
        preOrderList(head->right);
    }
}

tree::~tree()
{
    for (int i=0;i<tree::nodeNeedDelete.size();i++)
    {
        free(tree::nodeNeedDelete[i]);
    }
}
int main()
{
    node *head= (node *)malloc (sizeof(node));
    head->num=11;
    head->left=NULL;
    head->right=NULL;
    tree *test;
    test->create(head,1);
    test->create(head,2);
    test->preOrderList(head);
}
