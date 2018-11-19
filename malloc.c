#include <stdio.h>
#include <string.h>
#include <assert.h>

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


  node_t* to_check = next_free;
  // set to_check to next_free
  // check if to_check is big enough
  // if so, allocate there
  // if not, set to_check to to_check->next
  // NOTE: Possibly the last one could have enough space, but it would be skipped here
  while(to_check->next != 0) {
    if (to_check->size >= to_allocate) {
      // set alloc_mem to to_check
      // set next_free to to_check + to_allocate
      // set alloc_mem->next to that spot
      // set next_free->size to alloc_mem->size - to_allocate
      // return alloc_mem
      node_t* alloc_mem = to_check;
      next_free = to_check + to_allocate;
      // NOTE: Not sure if this logic is correct
      alloc_mem->next = (struct node_t *)next_free;
      next_free->size = alloc_mem->size - to_allocate;
      return (char *)alloc_mem;
    } else {
      to_check = to_check->next;
    }
  }
  return 0;
}


// MY_FREE
int my_free(char* address) {
    printf("address %p\n", address);
    // set next_free->next to address->next
    // set to_dealloc to next_free
    // set next_free to address
    node_t* old_next_free = next_free;
    node_t* to_dealloc = (node_t*)address;
    old_next_free->next = to_dealloc->next;
    next_free = (node_t*)address;
    next_free->next = old_next_free;

    assert(next_free == (node_t*)address);
    return 1;
}


int test_malloc() {
    int admin_size = sizeof(node_t);

    printf("Starting to run malloc: \n");
    printf("memory: %p\n", memory);
    printf("next_free: %p\n", next_free);

    // Test that after allocating 5, next_free is new_var_pointer05 + admin_size + 5
    node_t* new_var_pointer05 = (node_t*)my_malloc(5);
    printf("new_var_pointer05: %p\n", new_var_pointer05);
    assert(next_free == new_var_pointer05 + admin_size + 5);

    // Test that after freeing new_var_pointer05, next_free is new_var_pointer05
    printf("\nStarting to free new_var_pointer05: \n");
    printf("next_free: %p\n", next_free);
    my_free((char*)new_var_pointer05);
    printf("next_free: %p\n", next_free);
    assert(next_free == new_var_pointer05);

    // Test that after allocating new_var_pointer5, it is equal to old new_var_pointer05
    node_t* new_var_pointer5 = (node_t*)my_malloc(5);
    printf("new_var_pointer5: %p\n", new_var_pointer5);
    assert(new_var_pointer5 == new_var_pointer05);

    // Test that after allocating 5, next_free is next_free + admin_size + 10
    node_t* new_var_pointer10 = (node_t*)my_malloc(10);
    printf("new_var_pointer10: %p\n", new_var_pointer10);
    assert(next_free = new_var_pointer10 + admin_size + 10);

    // Test that after deallocating new_var_pointer10, next_free does not change
    node_t* old_next_free = next_free;
    printf("\nStarting to free new_var_pointer10: \n");
    printf("next_free: %p\n", next_free);
    my_free((char*)new_var_pointer10);
    printf("old_next_free: %p\n", old_next_free);
    printf("next_free: %p\n", next_free);
    assert(next_free == old_next_free);

    // Test that if the requested amount exceeds the remaining space, it returns 0
    printf("\nStarting to free new_var_pointer10: \n");
    printf("next_free: %p\n", next_free);
    my_free((char*)new_var_pointer10);
    printf("next_free: %p\n", next_free);

    node_t* new_var_pointer1020 = (node_t*)my_malloc(1020);
    printf("new_var_pointer1020: %p\n", new_var_pointer1020);


    // Allocate something big, then something small, then deallocate

    return 1;
}



int main(){
    test_malloc();
    return 1;
}
