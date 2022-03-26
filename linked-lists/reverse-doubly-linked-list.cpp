/*
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode *newHead = nullptr;
    while(llist != nullptr) {
        DoublyLinkedListNode *newNode = new DoublyLinkedListNode(llist->data);
        newNode->next = newHead;
        if(newHead != nullptr) newHead->prev = newNode;
        newHead = newNode;
        llist = llist->next;
    }
    
    return newHead;
}

