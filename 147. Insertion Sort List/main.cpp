/*
    147. Insertion Sort List 
    Sort a linked list using insertion sort.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode * head) {
    struct ListNode ** max;
    int t;
    for(struct ListNode ** p = &head; *p; p=&(*p)->next){
        max = p;
        for(struct ListNode ** q = p;*q;q=&(*q)->next){
            if((*max)->val > (*q)->val){
                max = q;
            }
        }
        struct ListNode * t;
        t = (*p);
        *p = *max;
        *max = t;
        t = (*p)->next;
        (*p)->next = (*max)->next;
        (*max)->next = t;
    }
    return head;
}

int main(void){
    struct ListNode l[8];
    struct ListNode * head;
    for(int i=0;i<7;i++){
        l[i].val = 7-i;
        l[i].next = &l[i+1];
    }
    l[6].next = NULL;

    head = insertionSortList(&l[0]);
    for(struct ListNode*p=head;p;p=p->next)
        printf("%d -> ",p->val);
    puts("NULL");

    getchar();
    return 0;
}