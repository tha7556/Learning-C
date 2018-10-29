#include "react.h"
#include <stdlib.h>

//Creates a pointer to a reactor struct. the reactor contains a cell array of pointers of size MAX_CELLS, initially with no cells inside.
struct reactor *create_reactor() {
	struct reactor *reactor = calloc(1, sizeof(struct reactor));
	reactor->cells = calloc(MAX_CELLS, sizeof(struct cell *));
	reactor->count = 0;
	return reactor;
}

//Frees all of the memory associated with the reactor.
void destroy_reactor(struct reactor *reactor) {
	for (int i = reactor->count - 1; i >= 0; i--) {
		struct cell *cell = reactor->cells[i];
		free(cell->children);
		free(cell->callbacks);
		free(cell->callbackInfos);
		free(cell);
	}
	  free(reactor->cells); 
	  free(reactor);
}

//Creates a pointer to a new input struct. The pointer is added to the reactor cells array, and given the initial value passed
struct cell *create_input_cell(struct reactor *reactor, int initialValue) {
	struct cell *result = calloc(1, sizeof(struct cell));
	result->value = initialValue;
	result->children	= calloc(MAX_CHILDREN, sizeof(struct cell *));
	result->callbacks = calloc(MAX_CALLBACKS, sizeof(callback));
	result->callbackInfos = calloc(MAX_CALLBACKS, sizeof(int) * 2);
	result->callbackCount = 0;

	reactor->cells[reactor->count] = result;
	reactor->count++;
	return result;
}

//Creates a cell that performs a computation on one cell
struct cell *create_compute1_cell(struct reactor *reactor, struct cell *cell, compute1 function) {
	struct cell *compute = create_input_cell(reactor, function(cell->value));
	compute->functionA = function;

	cell->children[cell->childCount] = compute;
	cell->childCount++;
	return compute;
}

//Creates a cell that performs a computation on two cells
struct cell *create_compute2_cell(struct reactor *reactor, struct cell *leftCell, struct cell *rightCell, compute2 function) {
	struct cell *compute = create_input_cell(reactor, function(leftCell->value, rightCell->value));
	compute->functionB = function;
	compute->left = leftCell;
	compute->right = rightCell;

	int indexA = 0, indexB = 0;
	for (int i = 0; i < reactor->count; i++) {
		if (reactor->cells[i] == leftCell)
			indexA = i;
			else if (reactor->cells[i] == rightCell)
				indexB = i;
	}
	if (indexA < indexB) {
		leftCell->children[leftCell->childCount] = compute;
		leftCell->childCount++;
	} 
	else {
		rightCell->children[rightCell->childCount] = compute;
		rightCell->childCount++;
	}
	return compute;
}

//Gets the value of a cell
int get_cell_value(struct cell *cell) {
	return cell->value;
}

//Executes every previous callback function to keep the cell up to date
void execute_callback(struct cell *cell, int last_value) {
	for (int i = 0; i < cell->callbackCount; i++)
		if (cell->callbacks[i] && cell->callbackInfos[i] && cell->value != last_value)
			cell->callbacks[i](cell->callbackInfos[i], last_value);
}

//Sets the value of a cell, as well as all children cells. Also handles the callback
void set_cell_value(struct cell *cell, int new_value) {
	if (cell->functionA) {
		int last_value = cell->functionA(new_value);
		execute_callback(cell, last_value);
		cell->value = last_value;
	} 
	else if (cell->functionB) {
		int last_value = cell->functionB(cell->left->value, cell->right->value);
		execute_callback(cell, last_value);
		cell->value = last_value;
	} 
	else
		cell->value = new_value;
	for (int i = cell->childCount - 1; i >= 0; i--) {
		struct cell *child = cell->children[i];
		set_cell_value(child, cell->value);
	}
}

//Adds a callback to the cell. callBackInfo is a struct created by the test and passed in.
callback_id add_callback(struct cell *cell, void *callbackInfo, callback callback) {
	if (callback && callbackInfo) {
		cell->callbackInfos[cell->callbackCount] = callbackInfo;
		cell->callbacks[cell->callbackCount] = callback;
		cell->callbackCount++;
		return cell->callbackCount - 1;
	}
	return -1;
}

//Removes a callback from the cell
void remove_callback(struct cell *cell, callback_id id) {
	if (cell->callbackInfos[id] && cell->callbacks[id]) {
		cell->callbackInfos[id] = NULL;
		cell->callbacks[id] = NULL;
	}
}
