/**
 * @file   linked_list.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   December 2013
 * @brief  Specifies linked list functionality
 * 
 * Initialises nodes and lists and defines how nodes are added to lists.
 */

#include "linked_list.h"
#include <stdlib.h>

/**
 * Adds a node to a linked list
 * @param to_add pointer to node that's to be added
 * @param list pointer to the list that the node will be added to
 */
void add_to_list(node_ptr * to_add, list_ptr * list) {

  //Check the list is empty
  if ((*list)->head == NULL) {

    //first item in a list added to both head and tail
    (*list)->head = (*to_add);
    (*list)->tail = (*to_add);

  } else {

    /*Hold the current tail, add the new node to it's next,
     set tail to be the new node.*/
    node * old_tail = (*list)->tail;
    old_tail->next = (*to_add);
    (*list)->tail = (*to_add);

  }

}

/**
 * Initialises a node; allocates memory, populates the node with 
 * passed in data, set default values.
 * @param new_node pointer to the node to be initialised
 * @param in_data data content for node
 */
void init_node(node_ptr * new_node, void* in_data) {
  (*new_node) = calloc(1, sizeof (struct link_node));
  (*new_node)->next = NULL;
  (*new_node)->node_data = in_data;
}

/**
 * Initialises a linked list; allocates memory and set
 * default values
 * @param list pointer to list to be initialised
 */
void init_list(list_ptr * list) {
  (*list) = calloc(1, sizeof (struct node_list));
  (*list)->head = NULL;
  (*list)->tail = NULL;
}

/**
 * Returns a pointer to the node at the head of a list
 * @param list pointer to the list
 * @return pointer to node at head
 */
node_ptr get_head(list_ptr * list) {
  return (*list) -> head;
}

/**
 * Function returns the number of elements in a linked list
 * @param list the linked list
 * @return the number of elements
 */
int get_length(list_ptr * list){
  node_ptr iterator = (*list) -> head;
  int count = 0;
  
  while(iterator != NULL){
    iterator = iterator -> next;
    count ++;
  }
  
  return count;
}