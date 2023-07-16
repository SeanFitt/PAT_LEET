#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
vector<int> possiblelist(int in)
{
    vector<int> result;
    int counter=0;
    // if(in==3||in==1)
    // {
    //     return result;
    // }
    // if(in==2)
    // {
    //     result.push_back(1);
    //     return result;
    // }
    for(int i=1;i<=in/2;i++)
    {
        if(in%i==0)
        {
            result.push_back(i);
            counter++;
        }
    }
    return result;
}

bool repeatedSubstringPattern(string s) {
    int len=s.length();
    vector<int> v=possiblelist(len);
    bool flag=false;
    for(int i=0;i<v.size();i++)
    {
        // int sub_len=v[i];
        int index=v[i];
        if(flag)
        return true;
        flag=true;
        string pre=s.substr(0,index);
        while(index<s.length())
        {
            flag=true;
            string now_str=s.substr(index,v[i]);
            if(pre!=now_str)
            {
                flag=false;
                break;
            }
            index+=v[i];
        }
    }
    return flag;
}

int main()
{
    string input="abab";
    bool result=repeatedSubstringPattern(input);
    return 0;
}