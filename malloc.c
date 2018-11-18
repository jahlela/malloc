#include <stdio.h>
#include <string.h>

// Define node_t struct
typedef struct free_node {
    struct node_t* next;
    size_t size;
} node_t;

#define MEM_SIZE 1024
char memory[MEM_SIZE];
int not_called = 1;

// Initialize next_free
node_t* next_free = (node_t*)memory;

char* my_malloc(int amount) {
  printf("\n");            
  // Initialize next_free's next and size with memory
  if (not_called) {
    next_free->next = (struct node_t *)memory;
    next_free->size = MEM_SIZE - sizeof(node_t);
    not_called = 0;
  }

  printf("Amount requested: %d\n", amount);        
  // Calculate necessary space for newly allocated memory
  size_t to_allocate = amount + sizeof(node_t);
  printf("Size of node_t: %zu\n", sizeof(node_t));
  printf("Memory to allocate: %zu\n", to_allocate);
  printf("Remaining space: %zu\n", next_free->size);        
  // If size not enough for amount + sizeof(node_t), return 0
  if (next_free->size < to_allocate) {
    return 0;
  } else {
    // set alloc_mem to next_free
    // set next_free to next_free + to_allocate
    // set alloc_mem->next to that spot
    // set next_free->size to alloc_mem->size - to_allocate
    // return alloc_mem
    node_t* alloc_mem = next_free;
    next_free = next_free + to_allocate;
    alloc_mem->next = (struct node_t *)next_free;
    next_free->size = alloc_mem->size - to_allocate;
    return (char *)alloc_mem;
  }
}


// MY_FREE
int my_free(char* address) {
    printf("address %p\n", address);
    node_t* to_dealloc = (node_t*)&address;
    to_dealloc->next = (struct node_t *)next_free;

    return 1;
}


int main(){
    printf("Starting to run malloc: \n");
    printf("memory: %p\n", memory);
    printf("next_free: %p\n", next_free);    

    node_t* new_var_pointer05 = (node_t*)my_malloc(5);
    printf("new_var_pointer05: %p\n", new_var_pointer05);    

    node_t* new_var_pointer10 = (node_t*)my_malloc(10);
    printf("new_var_pointer10: %p\n", new_var_pointer10);

    node_t* new_var_pointer1020 = (node_t*)my_malloc(1020);
    printf("new_var_pointer1020: %p\n", new_var_pointer1020);    
}



// void run_malloc(int amount){
//     printf("Starting to run malloc: \n");
//     printf("next_free: %p\n", next_free);
//     printf("next_free->size: %p\n", (void *)next_free->size);
//     node_t* new_var_pointer = (node_t*)my_malloc(amount);
//     printf("new_var_pointer: %p\n", next_free);
//     printf("new_var_pointer->size: %p\n", (void *)next_free->size);
// }
//
//
// void run_my_free(char* address){
//     printf("Starting to run free: \n");
//     printf("next_free: %p\n", next_free);
//     printf("next_free->size: %p\n", (void *)next_free->size);
//     my_free(address);
//     printf("next_free: %p\n", next_free);
//     printf("next_free->size: %p\n", (void *)next_free->size);
// }
