#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct ListNode{
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	Solution();
	~Solution();
	vector<int> value;
	vector<int> printListFromTailToHead(ListNode* head){
        if(head != NULL){
            if(head->next != NULL)
                printListFromTailToHead(head->next);
            value.push_back(head->val);
        }
        return value;
    }
private: 
};

Solution::Solution()
{
}

Solution::~Solution()
{
}



void printList(ListNode *head)
{
 while (head != NULL)
 {
  cout << head->val << " ";
  head = head->next;
 }
 cout << endl;
}

/*
void dropList(ListNode *head)
{
 if (head == NULL) return;
 ListNode *temp;
 while (head != NULL)
 {
  temp = head->next;
  delete head;
  head = temp;
 }
}*/

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	vector<int> happy;
	for(int i = 0; i < 10; i++){
		ListNode *newnode = new ListNode(i);
		cur->next = newnode;
		cur = newnode;
	}
	
	printList(head);
	
	Solution s;
    happy = s.printListFromTailToHead(head);
	// printList(head);
	// dropList(head);
	for(auto num:happy)
		std::cout << num << std::endl;
	return 0;
}

/*
class Solution {
public:
    vector<int> value;
    vector<int> printListFromTailToHead(ListNode* head){
        if(head != NULL){
            if(head->next != NULL)
                printListFromTailToHead(head->next);
            value.push_back(head->val);
        }
        return value;
    }
};*/


