#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

//reverse chain
ListNode *reverse(ListNode *root) {
  ListNode *ppre=root, *pcur, *pnext;
  if(ppre==NULL || ppre->next==NULL)
    return ppre; // 0/1 node
  else { // >=2nodes
    pcur = ppre->next;
    pnext = pcur->next;
    ppre->next = NULL;
    pcur->next = ppre;
    while(pnext!=NULL) {
      ppre = pcur;
      pcur = pnext;
      pnext = pnext->next;
      pcur->next = ppre;
    }
    return pcur;
  }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  bool carry = 0;
  ListNode *dummyHead =new ListNode(0); // a fantanstic trick!
  ListNode *p = dummyHead;
  int num;
/*
  ListNode *root, *p;
  int num = l1->val + l2->val;
  root = p = new ListNode(num%10);
  carry = num/10;
  l1 = l1->next; l2 = l2->next;
*/
  while(l1 && l2) {
    num = l1->val + l2->val + carry;
    p = p->next = new ListNode(num%10);
    carry = num/10;
    l1 = l1->next; l2 = l2->next;
  }
  // p->next = l1!=NULL? l1 : l2;
  // WRONG! not cover the case: [5,9]+[5] = [0,0,1]
  ListNode *second = l1!=NULL? l1 : l2;
  while(second) {
    num = second->val + carry;
    p = p->next = new ListNode(num%10);
    carry = num/10;
    second = second->next;
  }
  if(carry)
    p->next = new ListNode(carry);
  return dummyHead->next;
}

int main(void)
{
  ListNode *l1 = new ListNode(2); l1->next = new ListNode(4); l1->next->next = new ListNode(3); // 342
  ListNode *l2 = new ListNode(5); l2->next = new ListNode(6); l2->next->next = new ListNode(4); // 465
  ListNode *l = addTwoNumbers(l1, l2);
  while(l) {
    cout << l->val; // 708
    l = l->next;
  }
  return 0;
}

