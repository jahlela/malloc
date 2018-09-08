#include <stdio.h>

// int a = 1025;
// int *p;
// p = &a; // address of a
// *p <- value at p, ie the value at address of a
// &p <- address of p


// malloc
// IN: size_t amount, the size in memory to be allocated
// OUT: char* address, the location in memory allocated, 0 if none available
// maintains a next_free variable that points to the head of a linked list
// each node in the linked list points to the next available spot in memory
// each spot in memory as it is allocated takes size + 1 space

// When a spot is allocated:
// - The first value in this spot is overwritten to be the size of the allocated memory//
// - next_free must be updated to the previous next_free + size allocated + 1 (for size)


// free
// IN: size_t amount, the size in memory to be allocated
// OUT: int error, where 0 is no error, and any other value could be mapped to errors
// Splices an address in memory into the linked list of free spots
// When a spot is freed:
// 
// 
// 
// Tests:
// - Is memory initialized, and the correct size
// - Is next_free initialized to 0
// - Can malloc be called with something smaller than the remaining memory
//   - First time: return 0, and set next_free to amount + 2
//   - Next times: return next_free, and set next_free += 2 += amount
// - Can malloc be called with something too big?
//   - Traverse from next_free to end and return 0 if nothing is large enough
// - 


// atoi: ascii to int, 

int main(){
    return 0;
}



// FREE_T
typedef struct free_block {
    struct free_block* next;
    size_t size;
} free_t;

#define MEM_SIZE 1024

// INITIALIZE not_called, memory, next_free
int not_called = 1;
char memory[MEM_SIZE];
free_t* next_free = (free_t *)memory;


// MY_MALLOC
char* my_malloc(size_t amount) {
    // If first call, set first values of memory to 0 and the remaining free memory
    if (not_called) {
        next_free->next = 0;
        next_free->size = MEM_SIZE - sizeof(free_t);
        not_called = 0;
    }

//    printf("next: %d\n",next_free->next);
//    printf("size: %d\n",next_free->size);    

    // If size not enough for amount + 2, return 0
    if ( next_free->size < (amount + sizeof(free_t))) {
        return 0;
    } else {
        // set next_free->next to next_free->next + amount
        // return the address of the old next_free->next
//        next_free->next = 
        return (char*)next_free;
    }
    
    return (char *)next_free;
}


// MY_FREE
int my_free(char* address) {
    int success = 1;
    if (success) {
        return 0;
    }
    return 1;
}
