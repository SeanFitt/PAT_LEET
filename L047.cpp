#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++)
        {
            if(stk.size()!=0&&s[i]==stk.top())
            stk.pop();
            else
            stk.push(s[i]);
        }        
        int len=stk.size();
        char* re=(char*)calloc(len+1,sizeof(char));
        for(int i=0;i<len;i++)
        {
            re[len-i-1]=stk.top();
            stk.pop();
        }
        return re;
    }
};