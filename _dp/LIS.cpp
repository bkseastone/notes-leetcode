#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  const int _l[] = {0,1,9,8,0,2,3};
  const int N = sizeof(_l)/sizeof(int);
  vector<int> F(N, 0);
  /*最长递增子序列
    S: F_k: 以第k个元素为递增子序列结尾元素，对应的子序列长度。
    Q: max(F_i), i \belong [0,N)
trans:
    * F_0 = 1
    * F_k = \max {l_k>l_i?F_i+1:F_i, i \belong [0,k)}
  */
  F[0] = 1;
  for(int k=1; k<N; ++k) {
    F[k] = 1;
    for(int i=0; i<k; ++i)
      if(_l[k]>_l[i] && (F[i]+1)>F[k])
        F[k] = F[i]+1;
  }
  int maxF = 0;
  for(int k=0; k<N; ++k)
    if(maxF < F[k])
      maxF = F[k];
  cout << maxF << endl;

  return 0;
}

