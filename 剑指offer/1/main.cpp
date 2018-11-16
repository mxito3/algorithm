#include "iostream"
using namespace std;
#include <algorithm>
#include <vector>
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    	bool result=false;
		if(!array.empty())
		{
			for(int i=0;i<array.size();i++)
			{
				vector<int>::iterator it=find(array[i].begin(),array[i].end(),target);
				if(it!=array[i].end())
				{
					result=true;
				}
			}
		}        
		return result;
    }
};

int main()
{
	std::vector< std::vector<int> >array;
	array.push_back(std::vector<int>(5));
	array.push_back(std::vector<int>(5));
	array.push_back(std::vector<int>(5));
	for(int i=0;i<array.size();i++)
	{
		for(int j=0;j<array[0].size();j++)
		{
			array[i][j]=i+j;
			cout<<array[i][j]<<"  ";
		}
		cout<<endl;
	}

	Solution *s =new Solution();
	cout<< s->Find(1, array);

}