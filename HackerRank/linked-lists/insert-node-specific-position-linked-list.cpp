/*
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *head = llist;
    if(llist == nullptr || position == 0) {
        head = newNode;
        newNode->next = llist;
    } else {
        int counter = 0;
        while(llist != nullptr) {
            if(counter == position-1) break;
            llist = llist->next;
            counter++;
        }
        SinglyLinkedListNode *aux = llist->next;
        llist->next = newNode;
        newNode->next = aux;
    }
    
    return head;
}

