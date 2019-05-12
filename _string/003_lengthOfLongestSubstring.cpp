#include <memory.h>
#include <iostream>
#include <string>
using namespace std;

#define ms(a,int_v) memset((a),(int_v),sizeof(a))

int lengthOfLongestSubstring(string s) {
  int len=0, LS=0;
  bool table[256] = {false};
  ms(table, 0);
  for(int i=0; i<s.size(); ++i) {
    char c = s[i];
    if(table[c]) { // seen before
      if(LS<len) LS = len;
      len = 0;
      ms(table, 0);
      for(int j=i-1; j>=0; --j) { // re-locate
        if(s[j]==c) {
          i = j;
          break;
        }
      }
    }
    else {
      ++len;
      table[c] = true;
    }
  }
  if(LS<len) LS = len;
  return LS;
}

int main(void)
{
  string s("dvdf");
  cout << lengthOfLongestSubstring(s) << endl;
  return 0;
}
