/*
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data){
    DoublyLinkedListNode *newDoublyLinkedList = llist;
    DoublyLinkedListNode *head = newDoublyLinkedList;
    DoublyLinkedListNode *aux;
    DoublyLinkedListNode *curr;
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);

    /*
        2 <-> 3 <-> 4
        1
        curr = 2
        aux = null
    */
    bool inserted = false;
    while(llist != nullptr) {
        curr = newDoublyLinkedList;
        aux = newDoublyLinkedList->prev;

        if(newDoublyLinkedList->data > data) {
            if(aux != nullptr) aux->next = newNode;
            else head = newNode;
            newNode->prev = aux;
            newNode->next = curr;
            curr->prev = newNode;
            inserted = true;
            break;
        }

        llist = llist->next;
        newDoublyLinkedList = newDoublyLinkedList->next;
    }
    
    // node will be inserted in the end
    // 1<->2<->3->     <-4
    if(!inserted) {
        curr->next = newNode;
        newNode->prev = curr;   
    }
    
    return head;
}

