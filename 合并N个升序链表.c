#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	struct ListNode *ret = NULL, *p = NULL;

	while (1) {
		int min_val = 10003;
		int min_index;

		for (int i = 0; i < listsSize; ++i)
			if (lists[i] != NULL && lists[i]->val < min_val) {
				min_val = lists[i]->val;
				min_index = i;
			}

		if (min_val == 10003)
			break;

		if (ret == NULL) {
			ret = lists[min_index];
			p = ret;
		} else {
			p->next = lists[min_index];
			p = p->next;
		}

		lists[min_index] = lists[min_index]->next;
	}

	return ret;
}
