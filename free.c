#include <stdio.h>
#include <string.h>

// int a = 1025;
// int *p;
// p = &a; // address of a
// *p is value at p, ie the value at address of a
// &p is address of p


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


/*
 *
 *  virtual memory:
 *     0 | noise | program source in assembly bytecode |  stack | constants  
 *     0 | noise | program source in assembly bytecode |  stack | cons | memory = heap
 *
 *
 *
 *
 */

// Everything is an integer

// FREE_T
typedef struct free_block {
    struct free_block* next;
    size_t size;
} free_t;


#define MEM_SIZE 1024

// Define memory
char memory[MEM_SIZE];

// Define and initialize not_called and next_free
int not_called = 1;
free_t * next_free = (free_t *)memory;

// MY_MALLOC
char * my_malloc(size_t amount) {
    // If first call, set first values of memory to 0 and the remaining free memory
    if (not_called) {
        next_free->next = 0;
        next_free->size = MEM_SIZE - sizeof(free_t);
        not_called = 0;
        int new_free = (int)next_free;
        printf("new_free: %i\n",new_free);
        printf("*memory: %d\n", *memory);
        printf("memory: %p\n", memory);
        char * memory1 = memory;
        printf("memory1: %p\n", memory1);
        int  * memory2 = (int *)memory;
        printf("memory2: %p\n", memory2);        
        
        
        *(free_t**)memory = next_free;
        // free_t is a custom-defined struct, which is a type
        // free_t* is a pointer to a free_t
        // free_t** is a pointer to a pointer to a free_t
        // *(free_t**) 
        next_free->next = (free_t *)(&memory[amount]);
    }

    printf("next: %p\n", next_free->next);
    printf("size: %p\n", (void *)next_free->size); // printf("size: %p\n",(void *)next_free->size); // (void *)next_free->size);
    printf("amount: %zu\n", amount); // printf("amount: %p\n",(void *)amount->size);



    // If size not enough for amount + 2, return 0
    size_t to_allocate = amount + sizeof(free_t);
    printf("to_allocate: %zu\n",to_allocate);
    if ( next_free->size < to_allocate) {
        return 0;
    } else {
        // set next_free->next to next_free->next + amount
        // return the address of the old next_free->next
        // next_free->next =
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


int main(){
    char* new_var_pointer = my_malloc(5);
    printf("new_var_pointer: %p\n", new_var_pointer);
    return 0;
}


    //
    // printf("next: %p\n", next_free->next);
    // printf("size: %p\n", (void *)next_free->size); // printf("size: %p\n",(void *)next_free->size); // (void *)next_free->size);
    // printf("amount: %zu\n", amount); // printf("amount: %p\n",(void *)amount->size);




/*
        char str[] = "November";
        printf("Length of String is %d\n", strlen(str));
        printf("mem of String is %d\n", strlen(str) * sizeof(str);
        printf("Size of String is %lu\n", sizeof(str));
*/
