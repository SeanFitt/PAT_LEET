#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
string reverseLeftWords(string s, int n) {
    return s.substr(n,s.length()-1).append(s.substr(0,n));
}
int main(){
    string re=reverseLeftWords("lrloseumgh",6);
    return 0;
}
