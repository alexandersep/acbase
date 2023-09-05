#ifndef DLL_H
#define DLL_H

// Doubly Linked List Node
struct dllNode {
    float val;
    struct dllNode* next;
    struct dllNode* prev;
};

// Doubly Linked List
struct dll {
    struct dllNode* head;
    struct dllNode* tail;
};

// DLL init
// Summary: Instantiates a DLL struct pointer on the heap
// Returns: DLL Struct Pointer
struct dll * dll_init();

// DLL insert first 
// Summary: Insert a float val at the head of a dll
void dll_insert_head(struct dll* dll, float val);

// DLL insert last 
// Summary: Insert a float val at the tail of a dll
void dll_insert_tail(struct dll* dll, float val);

// DLL insert tail unique
// Summary: Insert a float val in tail if it is unique to the dll 
void dll_insert_tail_unique(struct dll* dll, float val);

// DLL insert head unique
// Summary: Insert a float val in head if it is unique to the dll 
void dll_insert_head_unique(struct dll* dll, float val);

// DLL lookup first
// Summary: Looks for a float val given a dll and a float starting from the head
// Returns: 1 when found
//          0 when not found
int dll_lookup_head(struct dll* dll, float val);

// DLL lookup last
// Summary: Looks for a float val given a dll and a float starting from the tail
// Returns: 1 when found
//          0 when not found
int dll_lookup_tail(struct dll* dll, float val);

// DLL remove first
// Summary: Removes head of dll
void dll_remove_head(struct dll* dll);

// DLL remove last
// Summary: Removes tail of dll
void dll_remove_tail(struct dll* dll);

// DLL print
// Summary: Prints the dll in order
void dll_print(struct dll* dll);

// DLL print reverse
// Summary: Prints the dll in reverse 
void dll_print_reverse(struct dll* dll);

// DLL free
// Summary: Frees the dll using free
void dll_free(struct dll* dll);

#endif
