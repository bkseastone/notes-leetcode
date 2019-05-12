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

ListNode *reverse(ListNode *pHead)
{
  ListNode *ppre=pHead, *pcur, *pnext;
  /* >=1 */
  if(ppre) { 
    pcur = ppre->next;
    /* >=2 */
    if(pcur) pnext = pcur->next; 
    else return ppre; // only 1 node
  }
  else
    return NULL; // only 0 node

  /* >=3 */
  ppre->next = NULL;
  pcur->next = ppre;
  while(pnext) { 
    ppre = pcur; pcur = pnext; pnext = pnext->next;
    pcur->next = ppre;
  }
  return pcur;
}

int main(void)
{
  const int _a[] = {5,4,3,2,1}; 
  ListNode *pHead = new ListNode(_a[0]);
  ListNode *p = pHead;
  for(int i=1; i<5; ++i) {
    p->next = new ListNode(_a[i]);
    p = p->next;
  }

  p = reverse(pHead);
  while(p) {
    cout << p->val;
    p = p->next;
  }

  p = pHead;
  ListNode *t;
  for(int i=0; p!=NULL; ++i) {
    t = p->next;
    delete p;
    p = t;
  }
  return 0;
}
