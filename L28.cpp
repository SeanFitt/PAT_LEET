#include<string.h>
#include<string>
using namespace std;

/*haystack索引需要向后移动的值*/
int movement(string s)
{
    int len=s.length();
    for(int i=1;i<len-1;i++)
    {
        string s1=s.substr(0,i);
        string s2=s.substr(len-i,len);
        //找相同的前缀和后缀编码，找到后返回对应的移动步数
        if(s1==s2)
        return len-i+1;
    }
    /*没找到捏，那我只走一步好了😄*/
    return 1;
}

int strStr(string haystack, string needle) {
    //KMP algorithm
    int len1=haystack.length();
    int len2=needle.length();
    int index=0;
    //禁止越界😠   
    while(index<=len1-len2)
    {
        string s1=haystack.substr(index,len2);
        //让我是不是一样的俩狗登西😊
        if(s1==needle)
        return index;
        else{
            //不一样啊，那快让我看看从哪里开始劈叉滴捏😊
            string s2;
            for(int i=0;i<needle.length();i++)
            {
                //捏妈妈的小东西，被我找到了吧，嘻嘻
                if(s1[i]!=needle[i])
                {
                    s2=needle.substr(0,i+1);
                    break;
                }
            }
            //我index先润了捏
            index+=movement(s2);
        }
    }
    //你好，不用找了，一开始就是养的，我要宣读一款车的品牌，没错就是你👍BYD
    if(len1==len2&&haystack==needle)
    return 0;
    //什么嘛，从一开始就离心离德的登西💢
    return -1;
}
//测试用例罢了，乐
int main(){
    string haystack = "mississippi";
    string needle = "issip";
    int res = strStr(haystack, needle);
    printf("%d\n", res);
    return 0;
}