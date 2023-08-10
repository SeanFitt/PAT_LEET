#include<stdlib.h>
#include<string.h>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        //来个栈先
        stack<char> stk;
        //左括号压栈，右括号看栈顶是否配对
        for(int i=0;i<s.length();i++)
        {
            char a=s[i];
            switch(a){
                case '(':
                stk.push('(');
                break;
                case '[':
                stk.push('[');
                break;
                case '{':
                stk.push('{');
                break;
                //右括号下药看是否已经是空栈了不然空栈pop直接报错捏
                case ')':
                if(stk.size()!=0&&stk.top()=='(')
                stk.pop();
                else
                return false;
                break;
                case ']':
                if(stk.size()!=0&&stk.top()=='[')
                stk.pop();
                else
                return false;
                break;
                case '}':
                if(stk.size()!=0&&stk.top()=='{')
                stk.pop();
                else
                return false;
                break;
            }
        }
        return stk.empty();
    }
};
int main(){
    Solution* s=new Solution();
    string test="]";
    bool result=s->isValid(test);
    printf("%d",result);
    return 0;
}