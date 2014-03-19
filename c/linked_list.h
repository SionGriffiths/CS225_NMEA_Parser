/**
 * @file   linked_list.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   December 2013
 * @brief  Simple linked list accepting generic pointer to data.
 *
 * Defines the structure of a linked list and linked list
 * nodes which accept generic pointers to data.
 * Specifies functions for initialising nodes, linked lists and adding
 * nodes to lists.
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * A structure to represent a node in the list
     */
    typedef struct link_node {
        void* node_data;
        struct link_node * next;
    } node;

    /**
     * A structure to represent a linked list
     */
    typedef struct node_list {
        node* head;
        node* tail;
    } linked_list;


    typedef node * node_ptr;
    typedef linked_list * list_ptr;


    /**
     * Adds a node to a linked list
     * @param to_add pointer to node that's to be added
     * @param list pointer to the list that the node will be added to
     */
    void add_to_list(node_ptr * to_add, list_ptr * list);

    /**
     * Initialises a node; allocates memory, populates the node with 
     * passed in data, set default values.
     * @param new_node pointer to the node to be initialised
     * @param in_data data content for node
     */
    void init_node(node_ptr * new_node, void* in_data);

    /**
     * Initialises a linked list; allocates memory and set
     * default values
     * @param list pointer to list to be initialised
     */
    void init_list(list_ptr * list);

    /**
     * Returns a pointer to the node at the head of a list
     * @param list pointer to the list
     * @return pointer to node at head
     */
    node_ptr get_head(list_ptr * list);

    /**
     * Function returns the number of elements in a linked list
     * @param list the linked list
     * @return the number of elements
     */
    int get_length(list_ptr * list);

#ifdef	__cplusplus
}
#endif

#endif	/* LINKED_LIST_H */
