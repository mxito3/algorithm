#include "iostream"
#include "string.h"
#include <algorithm>
#include <stdio.h>
using namespace std;
class Solution {
public:
	void replaceSpace(char* str, int length) {
		static std::string test = str;
		int from = 0;
		std::string needFind=" ";
		string replaced = "%20";
		while (1)
		{
			int found = test.find(needFind, from);  //找到返回索引，找不到-1　　string::find
			if (found == -1)
			{
				break;
			}
			test.replace(found, needFind.size(), replaced);
			from = found;
		}
		for (int i=0;i<test.length();i++)
		{
			*(&str[i]) = test[i];  //解引用
		}
	}
};

int main ()
{
	const char * init = " helloworld";
	char *base = (char *)malloc(sizeof(init));
	strcpy(base, init);
	Solution * test = new Solution();
	test->replaceSpace(base, strlen(base));
	cout <<  base;
 }


