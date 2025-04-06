# Push-Swap

Push-Swap is a sorting algorithm that uses the Turk sort to sort a sequence of unique integers in ascending order using two stacks: `a` and `b`. This README describes the rules and available operations to perform the sorting.

## Stack Setup
- You have two stacks: `a` and `b`.
  - At the beginning, the stack `a` contains a random number of unique integers (both negative and positive).
  - The stack `b` is initially empty.

## Goal
The goal of the algorithm is to sort the integers in stack `a` in ascending order. To achieve this, you can use the following operations:

## Available Operations
- **sa (swap a)**: Swap the first two elements at the top of stack `a`.

- **sb (swap b)**: Swap the first two elements at the top of stack `b`.

- **ss**: Perform `sa` and `sb` at the same time.

- **pa (push a)**: Take the first element at the top of stack `b` and put it at the top of stack `a`.

- **pb (push b)**: Take the first element at the top of stack `a` and put it at the top of stack `b`.

- **ra (rotate a)**: Shift all elements of stack `a` upwards by one position. The first element becomes the last one.

- **rb (rotate b)**: Shift all elements of stack `b` upwards by one position. The first element becomes the last one.

- **rr**: Perform `ra` and `rb` at the same time.

- **rra (reverse rotate a)**: Shift all elements of stack `a` downwards by one position. The last element becomes the first one.

- **rrb (reverse rotate b)**: Shift all elements of stack `b` downwards by one position. The last element becomes the first one.

- **rrr**: Perform `rra` and `rrb` at the same time.


## Example

To illustrate how the operations work:
1. Initially, stack `a` could be `[3, -1, 5, 2]`, and stack `b` would be `[]`.
2. Use the available operations (e.g., `pb`, `ra`, `sa`, etc.) to sort the elements in stack `a`.

