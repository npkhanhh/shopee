#include <iostream>
#include <map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
      map<ListNode*, bool> m;
      while (head!=NULL){
        if(m.count(head) ==1) {
          return true;
          
        }
        m[head] = true;
      }
      return false;        
    }
};

int main() {
  return 0;
}
