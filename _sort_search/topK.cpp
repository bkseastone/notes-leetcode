#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
  vector<int> ret_null;
  if(input.size()>=k && k>0) { // note: 考虑到k<0的可能输入!
    vector<int> ret(k, 0);
    // 以堆栈的角度来思考优先队列的STL，故当采用小于号的比较函子时，跑到最前面的(top)是最大值（vector采用小于号做sort时跑到最前面的([0])是最小值）
    priority_queue<int, vector<int>, less<int> > maxheap; 
    for(int i=0; i<k; ++i) {
      maxheap.push(input[i]);
    }
    for(int i=k; i<input.size(); ++i) {
      if(maxheap.top()>input[i]) {
        maxheap.pop();
        maxheap.push(input[i]);
      }
    }
    for(int i=0; i<k; ++i) {
      ret[k-1-i] = maxheap.top();
      maxheap.pop();
    }
    return ret;
  }
  else
    return ret_null;
}

int main(void)
{
  const int _v[] = {4,5,1,6,2,7,3,8};
  vector<int> input(_v, _v+8);
  vector<int> ret = GetLeastNumbers_Solution(input, 4);
  for(int i=0; i<ret.size(); ++i)
    cout << ret[i];
  cout << endl;
  return 0;
}

