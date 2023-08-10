#include <string>
#include<math.h>
#include<stack>
using namespace std;
class Solution {
public:
    bool is_number(string s)
    {
        int len=s.length();
        if(len==1&&(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'))
        return false;
        else return true;
    }
    int convert(string s)
    {
        //是否为正数
        bool flag=s[0]!='-';
        int len=s.length();
        int re=0;
        int index=0;
        if(!flag) index=1;
        while(index<len)
        {
            re+=(int)pow(10,len-index-1)*(s[index]-'0');
            index++;
        }
        if (!flag)
        re=-re;
        return re;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int n=tokens.size();
        int num1,num2;
        for(int i=0;i<n;i++)
        {
            bool is_num=is_number(tokens[i]);
            if(is_num)
            {
                num.push(convert(tokens[i]));
            }
            else{
                num1=num.top();
                num.pop();
                num2=num.top();
                num.pop();
                switch (tokens[i][0])
                {
                case '+':
                    num.push(num2+num1);
                    break;
                case '-':
                    num.push(num2-num1);
                    break;
                case '*':
                    num.push(num2*num1);
                    break;
                case '/':
                    num.push(num2/num1);
                    break;
                }
            }
        }
        return num.top();
    }
};
int main()
{
    string str[]={"2","1","+","3","*"};
    vector<string> test(str,str+5);
    Solution s;
    int result=s.evalRPN(test);
    return 0;
}