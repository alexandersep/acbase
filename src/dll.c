#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/dll.h"

struct dll * dll_init() {
    struct dll* dll = malloc(sizeof(struct dll));    
    assert(dll != NULL);
    dll->tail = NULL;
    dll->head = NULL; // head == tail
    return dll;
}

void dll_insert_head(struct dll* dll, float val) {
    struct dllNode* node = malloc(sizeof(struct dllNode));
    assert(node != NULL);
    node->val = val;
    node->prev = NULL;
    node->next = dll->head;

    // if dll is empty
    if (dll->head == NULL) {
        dll->head = node;
        dll->tail = node;
    } else {
        node->next = dll->head;
        dll->head->prev = node;
        dll->head = node;
    }
}

void dll_insert_tail(struct dll* dll, float val) {
    struct dllNode* node = malloc(sizeof(struct dllNode));
    assert(node != NULL);
    node->val = val;
    node->next = NULL;
    node->prev = dll->tail;

    // if dll is empty
    if (dll->tail == NULL) {
        dll->tail = node;
        dll->head = node;
    } else {
        node->prev = dll->tail;
        dll->tail->next = node;
        dll->tail = node;
    }
}

void dll_insert_tail_unique(struct dll* dll, float val) {
    struct dllNode* it;
    struct dllNode* node = malloc(sizeof(struct dllNode));
    int is_in_list = 0;
    assert(node != NULL);

    for (it = dll->head; it != NULL; it = it->next) {
        if (it->val == val) {
            is_in_list = 1;
            break;
        }
    }

    // if unique
    if (!is_in_list) {
        struct dllNode* node = malloc(sizeof(struct dllNode));
        assert(node != NULL);
        node->val = val;
        node->next = dll->head;
        node->prev = dll->tail;
        dll->tail->next = node;
        dll->tail = node;
    }
}

void dll_insert_head_unique(struct dll* dll, float val) {
    struct dllNode* it;
    struct dllNode* node = malloc(sizeof(struct dllNode));
    int is_in_list = 0;
    assert(node != NULL);

    for (it = dll->head; it != NULL; it = it->next) {
        if (it->val == val) {
            is_in_list = 1;
            break;
        }
    }

    // if unique
    if (!is_in_list) {
        struct dllNode* node = malloc(sizeof(struct dllNode));
        assert(node != NULL);
        node->val = val;
        node->next = dll->head;
        node->next = dll->head;
        dll->head->prev = node;
        dll->head = node;
    }
}

int dll_lookup_head(struct dll* dll, float val) {
    struct dllNode* it;
    for (it = dll->head; it->next != NULL; it = it->next) {
        if (it->val == val) {
            return 1;
        }
    }
    return 0;
}

int dll_lookup_tail(struct dll* dll, float val) {
    struct dllNode* it;
    for (it = dll->tail; it->prev != NULL; it = it->prev) {
        if (it->val == val) {
            return 1;
        }
    }
    return 0;
}

void dll_remove_head(struct dll* dll) {
    struct dllNode* node = dll->head;

    // if dll is empty nothing to remove
    if (dll->head == NULL) {
        return;
    }

    // if length of dll is 1
    if (dll->head == dll->tail) {
        dll->head = NULL;
        dll->tail = NULL;
    } else {
        dll->head = dll->head->next;
        dll->head->prev = NULL;
    }
    free(node);
}

void dll_remove_tail(struct dll* dll) {
    struct dllNode* node = dll->tail;

    // if dll is empty nothing to remove
    if (dll->tail == NULL) {
        return;
    }

    // if length of dll is 1
    if (dll->head == dll->tail) {
        dll->head = NULL;
        dll->tail = NULL;
    } else {
        dll->tail = dll->tail->prev;
        dll->tail->next = NULL;
    }
    free(node);
}

void dll_print(struct dll* dll) {
    struct dllNode* it;
    printf("Printing dll starting from head\n");
    printf("-------------------------------\n");
    for (it = dll->head; it != NULL; it = it->next) {
        printf("%f ", it->val);     
    }
    printf("\n-------------------------------\n");
}

void dll_print_reverse(struct dll* dll) {
    struct dllNode* it;
    printf("Printing dll starting from tail\n");
    printf("-------------------------------\n");
    for (it = dll->tail; it != NULL; it = it->prev) {
        printf("%f ", it->val);     
    }
    printf("\n-------------------------------\n");
}

void dll_free(struct dll* dll) {
    struct dllNode* curr;
    struct dllNode* next;
    for (curr = dll->head; curr != NULL; curr = next) {
        next = curr->next;
        free(curr);
    }
    free(dll);
}
