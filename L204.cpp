#include<stdlib.h>
#include<string>
using namespace std;
bool isAnagram(string s, string t) {
    int* counter_s=(int*)calloc(5001,sizeof(int));
    int* counter_t=(int*)calloc(5001,sizeof(int));
    if(s.length()!=t.length())
        return false;
    for(int i=0;i<s.length();i++)
    {
        counter_s[s.at(i)]++;
    }
    for(int i=0;i<t.length();i++)
    {
        counter_t[t.at(i)]++;
    }
    for(int i=0;i<5001;i++)
    {
        if(counter_s[i]!=counter_t[i])
        return false;
    }
    return true;
}