#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
vector<string> commonChars(vector<string>& words) {
    int word=words.size();
    int** counter=(int**)calloc(26,sizeof(int*));
    for(int i=0;i<26;i++)
    {
        counter[i]=(int*)calloc(word,sizeof(int));
    }
    for(int i=0;i<word;i++)
    {
        string now_word=words.at(i);
        for(int j=0;j<now_word.length();j++)
        {
            counter[i][now_word[j]-'a']++;
        }
    }
    char re[26];
    int index=0;
    for(int j=0;j<26;j++)
    {
        bool flag=true;
        for(int i=0;i<26;i++)
        {
            if(counter[i][j]<word)
            {
                flag=false;
                continue;
            }
        }
        if(flag=true)
        re[index++]=j+'a';
    } 
    re[index]='\0';
    string re=string(re);
    vector<string> fre;
    fre.push_back(re);
    return fre;
}