#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == nullptr) {
        return;
    }

    Node *& next_smaller = smaller;
    Node *& next_larger = larger;
    if (head->val > pivot) {
        // Go into larger
        if (larger == nullptr) {
            larger = head;
        } else {
            larger->next = head;
            next_larger = head;
        }
    } else {
        // Go into smaller
        if (smaller == nullptr) {
            smaller = head;
        } else {
            smaller->next = head;
            next_smaller = head;
        }
    }
    Node *&next = head->next;
    head->next = nullptr;
    
    llpivot(next,next_smaller,next_larger,pivot);

 //create a temp variable
 Node* temp = head;
 //this variable will transverse the list
 if(temp==nullptr) {
   head=nullptr;
 }
 if(temp->val > pivot) {
   larger=temp;
   larger=larger->next;
 }
 if(temp->val < pivot) {
   smaller=temp;
   smaller=smaller->next;
	
 }
 llpivot(temp->next, smaller, larger, pivot);
}




