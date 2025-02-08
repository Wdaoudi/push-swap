# Push_swap
<div align="center">
  <img src="https://img.shields.io/badge/norminette-passing-success"/>
  <img src="https://img.shields.io/badge/42-project-000000"/>
</div>

## 💡 About
> An efficient number sorting project that implements a custom sorting algorithm using two stacks with a limited set of operations.

This project challenges you to sort data using two stacks and a specific set of operations, focusing on optimization and algorithm efficiency. The goal is to sort the numbers using the minimum possible moves.

## 🛠️ Usage
### Requirements
- GCC compiler
- Make
- A Unix-based operating system

### Instructions
**1. Compiling**
```shell
$ git clone https://github.com/wdaoudi-/push_swap
$ cd push_swap
$ make
```

**2. Using it**
```shell
$ ./push_swap 2 1 3 6 5 8
```
The program will output a list of operations that will sort the numbers.

## 📋 Features

| Operation | Description |
|-----------|-------------|
| sa (swap a) | Swap first two elements of stack a |
| sb (swap b) | Swap first two elements of stack b |
| ss | sa and sb at the same time |
| pa (push a) | Take the first element at the top of b and put it at the top of a |
| pb (push b) | Take the first element at the top of a and put it at the top of b |
| ra (rotate a) | Shift up all elements of stack a by 1 |
| rb (rotate b) | Shift up all elements of stack b by 1 |
| rr | ra and rb at the same time |
| rra (reverse rotate a) | Shift down all elements of stack a by 1 |
| rrb (reverse rotate b) | Shift down all elements of stack b by 1 |
| rrr | rra and rrb at the same time |

## 📊 Performance Benchmarks
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

## 💫 Bonus Features
- Checker program: Verifies if the sorting operations actually sort the stack
```shell
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

## Error Management
- Displays "Error" if:
  - Some arguments aren't integers
  - Some arguments are greater than INT_MAX or less than INT_MIN
  - There are duplicate numbers
  - An argument is missing or invalid

## Implementation Details
- Written in C
- Follows 42 School's coding standards (norminette)
- No memory leaks
- Efficient sorting algorithms for different stack sizes
- Optimized operation selection to minimize moves

---
Made with ❤️ by wdaoudi-
