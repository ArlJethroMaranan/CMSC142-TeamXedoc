# Combination & Dynamic Programming (C)

James Bryan Gregorio
Arl Jethro Maranan
André Luis Noche
Gift Moses Perez
Martin Adrian Plaza

This repository contains **four standalone C programs** that explore **combinatorics and subset sum problems** using backtracking and dynamic programming techniques.

## Overall Goal of the Programs

Taken together, these programs aim to:
- Generate combinations (subsets) of integers
- Filter combinations based on a target sum
- Demonstrate different strategies for solving subset sum problems, including:
  - simple backtracking
  - constrained combinations
  - extending a fixed initial subset
  - dynamic programming with solution reconstruction

Each program is independent and can be compiled and run separately.

---

## 1. `combination.c`

### Program Overview
This program generates **all possible combinations** of the integers from `1` to `N` (where `N = 5`) using backtracking.

### Expected Output
- Each line represents one combination
- Numbers appear in increasing order within a combination

Example:
```
1
12
123
134
5
```

### How to Run
```
gcc combination.c && ./a.out
```

---

## 2. `comb_with_sum.c`

### Program Overview
This program generates combinations of numbers from `1` to `N` (`N = 5`) whose **sum equals a target value `k`** (`k = 10`).  
It prints only the combinations whose elements add up exactly to the target.

### Expected Output
Each line contains a valid subset whose sum is `10`.

Example:
```
5 3 2
4 3 2 1
```

### How to Run
```
gcc comb_with_sum.c && ./a.out
```

---

## 3. `comb_with_init_subset.c`

### Program Overview
This program begins with a **fixed initial subset** `{4, 1, 3}` and attempts to extend it to reach a target sum of `25`.  
It computes the remaining required sum and uses backtracking to find valid numbers that complete the subset.

### Expected Output
- Every line starts with the initial subset:
  ```
  4 1 3
  ```
- Additional numbers complete the total sum to `25`

### How to Run
```
gcc comb_with_init_subset.c && ./a.out
```

---

## 4. `dynamic_prog.c`

### Program Overview
This program demonstrates a **dynamic programming–based subset sum solution**.

Steps performed:
1. Sorts the input set using Shell sort
2. Builds a 2D subset sum table showing reachable sums
3. Prints the subset sum table
4. Traces and prints one valid subset whose sum equals `K = 10`

### Expected Output
- A matrix displaying reachable sums
- A printed subset such as:
  ```
  One subset that sums to 10: 2 3 5
  ```

### How to Run
```
gcc dynamic_prog.c && ./a.out
```

---

## Compilation Notes
- All programs use standard C
- No external libraries are required
- General compile-and-run command:
```
gcc filename.c && ./a.out
```

---

## Summary
These programs collectively demonstrate multiple approaches to solving **combination generation** and **subset sum** problems in C, making them useful as learning references for backtracking and dynamic programming.
