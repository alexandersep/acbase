#ifndef LA_H
#define LA_H

// Linked "List" Array 
struct la {
    int size; // size of struct
    int filled; // number of filled slots
    float* arr;
};

// LA init
// Summary: Initialise the LA struct pointer on the heap
// Returns: LA Struct Pointer
struct la* la_init(int size);

// LA insert
// Summary: Insert a value to the LA
void la_insert(struct la* la, float val);

// LA remove
// Summary: Remove last element from LA
void la_remove(struct la* la);

// LA insert times
// Summary: Insert a value to the LA "times" times
void la_insert_times(struct la* la, float val, int times);

// LA reverse
// Summary: Reverse LA modifying la in place
void la_reverse(struct la* la);

// LA print
// Summary: Print values of LA that are filled in
void la_print(struct la* la);

// LA print reverse
// Summary: Print values of LA that are filled in reverse order
void la_print_reverse(struct la* la);

// LA free
// Sumary: Free LA struct
void la_free(struct la* la);

#endif
