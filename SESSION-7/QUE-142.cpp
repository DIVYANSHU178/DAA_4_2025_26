/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *temp = head;
		ListNode *temp2 = head;
		while (temp2 && temp2->next)
		{
			temp = temp->next;
			temp2 = temp2->next->next;

			if (temp == temp2)
			{
				ListNode *ptr = head;
				while (ptr != temp)
				{
					ptr = ptr->next;
					temp = temp->next;
				}
				return ptr;
			}
		}
		return nullptr;
	}
};