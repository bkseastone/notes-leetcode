#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这种和快排相似的算法结构：前序遍历二叉树
TreeNode *R(vector<int> a, int abegin, int aend, vector<int> b, int bbegin, int bend)
{
  if(bbegin == bend)
    return NULL;
  TreeNode *root = new TreeNode(a[abegin]);
  int num_left=0;
  for(int i=bbegin; i<bend; ++i)
    if(b[i] == a[abegin]) {
      num_left = i - bbegin; // feature: 索引左闭右开, 实打实的个数即为偏移量.
      break;
    }
  root->left = R(a, abegin+1, abegin+1+num_left, b, bbegin, bbegin+num_left);
  root->right = R(a, abegin+1+num_left, aend, b, bbegin+num_left+1, bend);
  return root; // 重构即为递归寻找子树的根节点
}

void back(TreeNode *root)
{
  if(root) {
    back(root->right);
    back(root->left);
    cout << root->val;
  }
}

int main(void)
{
  const int _pre[] = {1,2,4,7,3,5,6,8};
  const int _vin[] = {4,7,2,1,5,3,8,6};
  cout << _len << endl;
  vector<int> pre(_pre, _pre+_len);
  vector<int> vin(_vin, _vin+_len);
  
  TreeNode *t = R(pre, 0, pre.size(), vin, 0, vin.size());

  back(t); // 86537421
  cout << endl;
  return 0;
}

