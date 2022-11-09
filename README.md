# 7 - Push_swap - 42cursus

## Abstract

The objective of this project is to create in C an algorithm that sorts a set of numbers as quickly as possible. For this we have two stacks called Stack_A and Stack_B. At the beginning Stack_A is initialized by a random number of numbers and given by Input the Stack_B is empty. These numbers must be sorted back on the Stack_A using a set of operations. The program must display the list of operations necessary. The following operations are allowed:

- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time

INPUTS: A set of numbers.\n
OUTPUTS: A set of operations.
