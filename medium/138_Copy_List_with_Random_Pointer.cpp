#include "../libstruct.h"

using namespace std;

/*
 * NO.138
 * A linked list is given such that each node contains an additional random pointer 
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        cloneNodes(head);
        connectNodes(head);
        return splitNodes(head);
    }
    
    void cloneNodes(RandomListNode *head) {
        RandomListNode *node = head;
        while (node) {
            RandomListNode *cloneNode = new RandomListNode(node->label);
            cloneNode->next = node->next;
            node->next = cloneNode;
            node = cloneNode->next;
        }
    }
    
    void connectNodes(RandomListNode *head) {
        RandomListNode *node = head, *cloneNode = NULL;
        while (node) {
            cloneNode = node->next;
            if (node->random) cloneNode->random = node->random->next;
            node = cloneNode->next;
        }
    }
    
    RandomListNode *splitNodes(RandomListNode *head) {
        RandomListNode *node = head, *cloneNode = NULL, *copyHead = head;
        if (copyHead) copyHead = copyHead->next;
        while (node) {
            cloneNode = node->next;
            node->next = cloneNode->next;
            node = node->next;
            cloneNode->next = node ? node->next : node;
        }
        return copyHead;
    }
};