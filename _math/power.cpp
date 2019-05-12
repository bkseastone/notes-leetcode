#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

double power(double base, int exponent)
{
  if(exponent==1) // NOTE: don't forget this branch!
    return base;
  else if(exponent>0) {
    /*
    if(exponent&1u)
      return power(base, exponent>>1) * power(base, exponent>>1+1);
    else {
      double ret = power(base, exponent>>1);
      return ret*ret;
    }
    */
    double ret = power(base, exponent>>1);
    ret *= ret;
    if(exponent&1u)
      ret *= base;
    return ret; 
  }
  else if(exponent==0)
    return 1;
  else { // <0
    if(base==0) {
      cout << "分母不能为0" << endl;
      return 0;
    }
    return 1/power(base, 0-exponent);
  }
}
int main(void)
{
  cout << power(2, 10) << endl; 
  return 0;
}

