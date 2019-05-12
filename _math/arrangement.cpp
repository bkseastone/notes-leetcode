#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
void _swap(T& a, T& b) { T c = a; a = b; b = c; }

vector<string> ret;
void perm(string& str, int begin) {
  if(begin == str.length())
    ret.push_back(str);
  for(int i=begin; i<str.length(); ++i) {
    if(i!=begin && str[i]==str[begin]) continue;
    swap(str[i], str[begin]);
    perm(str, begin+1);
    swap(str[i], str[begin]);
  }
}

vector<string> Permutation(string& str) {
  int len = str.length();
  if(len){
    perm(str, 0);     
    return ret; // NOTE: 没有return, 会导致Segmentation fault.
  }
  else
    return ret;
}

int main(void)
{
  string str("abc");

  Permutation(str);

  for(int i=0; i<ret.size(); ++i)
    cout << ret[i] << endl;
  return 0;
}
