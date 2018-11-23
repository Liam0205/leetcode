#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };


class Solution {
    class cmp {
        bool operator() (const ListNode*& a, const ListNode*& b) {
            return a->val < b->val;
        }
    };
    
    // void push(priority_queue<ListNode*, vector<ListNode*>, cmp>& heap, ListNode* val) {
    //     if (nullptr != val) {
    //         heap.push(val);
    //     }
    // }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Solution::cmp> heap;
        for (auto p : lists) {
            if (nullptr != p) {
                heap.push(p);
            }
        }
        
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        
        while (!heap.empty()) {
            ListNode* tmp = heap.top();
            p->next = new ListNode(tmp->val);
            p = p->next;
            if (nullptr != p) {
                heap.push(p);
            }
        }
        
        return res->next;
    }
};
