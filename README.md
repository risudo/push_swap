# push_swap
This project is to create effective sort algorithm.  
There are 2 stacks named A and B.  
To start with:  
- A contains a randam number of either positive or negative numbers without any duplicates.
- B is empty.

The goal is to sort in ascending order numbers into stack A.  
  
There is a set of instructions to manipulate both stacks.  
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

`push_swap` receives as an argument the stack a formatted as a list of integers.  
The program must display the smallest list of instructions possible to sort the stack a.

# Example

```
$ ./push_swap 3 2 1
sa
rra
```

```
$ ./push_swap 5 3 4 2 1
rra
pb
rra
pb
ra
pa
pa
```

# How efficient is it?
Use `test.sh` to test.  
`COUNT` means the number of arguments.
```
$ bash test.sh
```

approximately,  
- COUNT 100 : 600 ~ 700 instructions.
- COUNT 200 : 1500 ~ 1650 instructions.
- COUNT 300 : 2500 ~ 2700 instructions.
- COUNT 400 : 3600 ~ 3900 instructions.
- COUNT 500 : 4800 ~ 5100 instructions.




