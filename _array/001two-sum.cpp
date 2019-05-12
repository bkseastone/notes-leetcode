#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct PAIR { int num; int idx; };
int search(struct PAIR* & nums, int a, int begin, int end) {
  if(begin>=end) return -1; // not found
  int mid = begin + (end-begin)/2;
  if(a<nums[mid].num) return search(nums, a, begin, mid);
  else if(a>nums[mid].num) return search(nums, a, mid+1, end);
  else return nums[mid].idx;
}

int searchIndexBy2Split(struct PAIR* & nums, int rem, int begin, int end) {
  return search(nums, rem, begin, end);
}

int cmp_increase(const void *a, const void *b) {
  return (*(struct PAIR*)a).num - (*(struct PAIR*)b).num;
}

vector<int> twoSum(vector<int>& nums, int target) {
  int len = nums.size();
  struct PAIR *pnums = new struct PAIR[len];
  for(int i=0; i<len; ++i) {
    pnums[i].num = nums[i];
    pnums[i].idx = i;
  }
  qsort(pnums, len, sizeof(struct PAIR), cmp_increase);
  vector<int> res;
  for(int i=0; i<len; ++i) {
    int j = searchIndexBy2Split(pnums, target-pnums[i].num, i+1, len);
    if(j == -1)
      continue;
    else {
      res.push_back(pnums[i].idx); res.push_back(j);
      break;
    }
  }
  delete[] pnums;
  return res;
}

vector<int> twoSum2(vector<int>& nums, int target) {
  map<int, int> hashTable{};
  int len = nums.size();
  vector<int> res;
  for(int i=0; i<len; ++i) {
    auto rem = hashTable.find(target-nums[i]);
    if(hashTable.end() == rem) {
      hashTable.insert(make_pair(nums[i], i));
      continue;
    }
    else {
      res.push_back(rem->second);
      res.push_back(i);
      break;
    }
  }
  return res;
}

int main(void)
{
  vector<int> nums = {3, 2, 3};
  int target = 6;
  vector<int> output = twoSum2(nums, target);
  cout << '[' << output[0] << ", " << output[1] << ']' << endl;
  return 0;
}

