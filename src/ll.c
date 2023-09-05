#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/ll.h"

struct ll* ll_init() {
    struct ll* ll = malloc(sizeof(struct ll));
    assert(ll != NULL);
    ll->head=NULL;
    return ll;
}

int ll_lookup(struct ll* ll, float val) {
    struct llNode* p;
    for (p = ll->head; p != NULL; p = p->next) {
        if (p->val == val) {
            return 1;
        }
    }
    return 0;
}

void ll_insert_head(struct ll* ll, float val) {
    struct llNode* node = malloc(sizeof(struct llNode));
    assert(node != NULL);
    node->next = ll->head;
    ll->head = node;
    node->val = val;
}

void ll_insert_tail(struct ll* ll, float val) {
    struct llNode* curr;
    struct llNode* node = malloc(sizeof(struct llNode));
    assert(node != NULL);

    if (ll->head == NULL) {
        ll->head = node;
        node->val = val;
        return;
    }
    for (curr = ll->head; curr->next != NULL; curr = curr->next);
    curr->next = node;
    node->val = val;
}

void ll_insert_unique(struct ll* ll, float val) {
    struct llNode* it;
    int is_in_list = 0; // boolean, is item in list, if yes do nothing
    for (it = ll->head; it != NULL; it = it->next) {
        if (it->val == val) {
            is_in_list = 1;
            break;
        }
    }

    // if unique
    if (!is_in_list) {
        struct llNode* node = malloc(sizeof(struct llNode));
        assert(node != NULL);
        node->next = ll->head;
        ll->head = node;
        node->val = val;
    }
}

void ll_remove(struct ll* ll, float val) {
    struct llNode* curr;
    struct llNode* prev;

    // is the list empty?
    if (ll->head == NULL) {
        return;
    }

    // is the wanted item in first node of the list?
    if (ll->head->val == val) {
        curr = ll->head;
        ll->head = curr->next;
        free(curr);
        return;
    }

    // search remainder of the list for item
    for (prev = ll->head, curr = ll->head->next; curr != NULL; prev = curr, curr = curr->next) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    }
}

void ll_print(struct ll* ll) {
    struct llNode* it;
    printf("Printing ll in order\n");
    printf("-------------------------------\n");
    for (it = ll->head; it != NULL; it = it->next) {
        printf("%f ", it->val);     
    }
    printf("\n-------------------------------\n");
}

void ll_free(struct ll* ll) {
    struct llNode* current;
    struct llNode* next;
    // search remainder of the list for item
    for (current = ll->head; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
    free(ll);
}
