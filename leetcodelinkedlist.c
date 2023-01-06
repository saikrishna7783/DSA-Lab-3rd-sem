/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // Concatenating the 2 linked lists
    struct ListNode *curr = list1;
    if (list1 == NULL && list2 == NULL)
        return NULL;
    else if (list1 != NULL && list2 == NULL)
        return list1;
    else if (list1 == NULL && list2 != NULL)
        return list2;
    else
    {

        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = list2;
    }
    // Sorting the concatenated linked list
    int temp;
    curr = list1;
    while (curr->next != NULL)
    {
        struct ListNode *check = curr->next;
        while (check != NULL)
        {
            if ((curr->val) > (check->val))
            {
                temp = curr->val;
                curr->val = check->val;
                check->val = temp;
            }
            check = check->next;
        }
        curr = curr->next;
    }
    return list1;
}
