/*
 *
 * struct Node {
 *     int data;
 *     struct Node* next;
 * }
 *
*/

bool has_cycle(Node* head) {
    // two pointers slow fast technique
    if(head == nullptr or head->next == nullptr) return false;
    Node *slow = head;
    Node *fast = head->next;
    
    while(slow != fast) {
        if(fast == nullptr or fast->next == nullptr) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return true;
}

