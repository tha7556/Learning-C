#ifndef REACT_H
#define REACT_H

//Max number of possible cells inside of a reactor
#define MAX_CELLS     5
//Max number of possible children for each cell
#define MAX_CHILDREN  2
//Max number of callbacks inside of a cell
#define MAX_CALLBACKS 3

//A pointer to a function with int return and 1 int param
typedef int (*compute1) (int);
//A pointer to a function with int return and 2 int params
typedef int (*compute2) (int, int);
//A pointer to a function with no return, a pointer and integer params
typedef void (*callback) (void *, int);
typedef int callback_id;

//Struct that holds pointers to all of the cells
struct reactor {
  struct cell **cells; //An array of pointers to the cells
  int count; //The number of cells
};
//An individual cell. Has an array of pointers to children cells, as well as a compute1, compute2, and call back related variables
struct cell {
  int value;
  struct cell **children; //Array of pointers to children cells
  int childCount; //Number of children cells

  compute1 functionA; //A function to perform an operation on a single cell
  compute2 functionB; //A function to perform an operation between two cells
  struct cell *left, *right; //Pointers to each side of the functionB operation

  void **callbackInfos; //An array of pointers to callBackInfo objects
  callback *callbacks; //An array of callbacks
  callback_id callbackCount; //The number of callbacks
};

struct reactor *create_reactor();
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *);

struct cell *create_input_cell(struct reactor *reactor, int initialValue);
struct cell *create_compute1_cell(struct reactor *reactor, struct cell *cell, compute1 function);
struct cell *create_compute2_cell(struct reactor *reactor, struct cell *left, struct cell *right, compute2 function);

int get_cell_value(struct cell *cell);
void execute_callback(struct cell *cell, int last_value);
void set_cell_value(struct cell *cell, int new_value);

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *cell, void *callbackInfo, callback);
void remove_callback(struct cell *cell, callback_id id);

#endif
