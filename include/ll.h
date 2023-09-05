#ifndef LL_H
#define LL_H

// Single Linked List Node
struct llNode {
    float val;
    struct llNode* next;
};

// Single Linked list
struct ll {
    struct llNode* head;
};

// LL init
// Summary: Instantiates an LL struct pointer on the heap
// Returns: LL Struct Pointer
struct ll* ll_init();

// LL lookup 
// Summary: Looks for a float val given an ll and a float
// Returns: 1 when found
//          0 when not found
int ll_lookup(struct ll* ll, float val);

// LL insert
// Summary: Insert a float val at the head of the ll
void ll_insert_head(struct ll* ll, float val);

// LL insert
// Summary: Insert a float val at the tail (end) of the ll
void ll_insert_tail(struct ll* ll, float val);

// LL insert unique
// Summary: Insert a float val if it is unique to the ll 
void ll_insert_unique(struct ll* ll, float val); 

// LL remove
// Summary: Removes head of the ll
void ll_remove(struct ll* ll, float val);

// LL print 
// Summary: Prints the ll in order
void ll_print(struct ll* ll);

// LL print reverse
// Summary: Prints the ll in reverse order O(N) memory for stack printing
// void ll_print_reverse(struct ll* ll);

// LL free
// Summary: Frees the ll using free
void ll_free(struct ll* ll);

#endif
