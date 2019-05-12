#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
  if(pHead1 && pHead2) {
    ListNode *p, *ret, *p1cur=pHead1, *p2cur=pHead2;
    /* decide root node */
    if(p1cur->val < p2cur->val) {
      p = ret = p1cur;
      p1cur = p1cur->next;
    }
    else {
      p = ret = p2cur;
      p2cur = p2cur->next;
    }
    /* start merge proc */
    while(p1cur && p2cur) {
      if(p1cur->val < p2cur->val) {
        p = p->next = p1cur;
        p1cur = p1cur->next;
      }
      else {
        p = p->next = p2cur;
        p2cur = p2cur->next;
      }
    }
    while(p1cur) {
      p = p->next = p1cur;
      p1cur = p1cur->next;
    }
    while(p2cur) {
      p = p->next = p2cur;
      p2cur = p2cur->next;
    }
    return ret;
  }
  else if(pHead1) return pHead1;
  else if(pHead2) return pHead2;
  else return NULL;
}

int main(void)
{
  const int _a1[] = {1,3,5}; 
  ListNode *pHead1 = new ListNode(_a1[0]);
  ListNode *p = pHead1;
  for(int i=1; i<3; ++i) { p->next = new ListNode(_a1[i]); p = p->next; }
  const int _a2[] = {2,4,6}; 
  ListNode *pHead2 = new ListNode(_a2[0]);
  p = pHead2;
  for(int i=1; i<3; ++i) { p->next = new ListNode(_a2[i]); p = p->next; }

  p = Merge(pHead1, pHead2);

  while(p) { cout << p->val; p = p->next; }
  cout << endl;
  return 0;
}
