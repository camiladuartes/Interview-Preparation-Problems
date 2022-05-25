/*
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* headList2 = head2;
    while(head1 != nullptr) {
        while(head2 != nullptr) {
            if(head1 == head2) return head1->data;
            head2 = head2->next;
        }
        head2 = headList2;
        head1 = head1->next;
    }
    return 0;
}

