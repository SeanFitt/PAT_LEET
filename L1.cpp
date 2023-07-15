#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct numbers
{
    int val;
    int index;
};
bool cmp(numbers a,numbers b)
{
    return a.val<b.val;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<numbers> num;
    for(int i=0;i<nums.size();i++)
    {
        numbers now;
        now.val=nums[i];
        now.index=i;
        num.push_back(now);
    }
    sort(num.begin(),num.end(),cmp);
    int left=0,right=num.size()-1;
    int now=0;
    while(left!=right)
    {
        now=num[left].val+num[right].val;
        if(now<target)
        left++;
        else if (now>target)
        right--;
        else
        break;
    }
    vector<int> result;
    result.push_back(num[left].index);
    result.push_back(num[right].index);
    return result;
}

int main()
{
    vector<int> in;
    in.push_back(3);
    in.push_back(2);
    in.push_back(4);
    int tar=6;
    vector<int> re=twoSum(in,tar);
    return 0;
}