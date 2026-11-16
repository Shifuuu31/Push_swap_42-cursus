# Stack Operations Reference & Specification

## 1. Overview

Push_swap operates on two stacks:
- **Stack A**: Contains the initial set of positive and negative integers in arbitrary order.
- **Stack B**: Initially empty, used as an auxiliary sorting buffer.

The program must manipulate these stacks exclusively using **11 primitive operations**. Every operation executed by the program is written to standard output (`stdout`) followed by a newline `\n`.

---

## 2. The 11 Operations

| Op | Name | Source Location | Description |
|---|---|---|---|
| `sa` | Swap A | `operations_a.c:40` | Swap the first 2 elements at the top of Stack A. Does nothing if size $\le 1$. |
| `sb` | Swap B | `operations_b.c:40` | Swap the first 2 elements at the top of Stack B. Does nothing if size $\le 1$. |
| `ss` | Swap Both | `operations_both.c:15` | Execute `sa` and `sb` simultaneously. |
| `pa` | Push A | `operations_a.c:15` | Take the first element at the top of B and put it at the top of A. Does nothing if B is empty. |
| `pb` | Push B | `operations_b.c:15` | Take the first element at the top of A and put it at the top of B. Does nothing if A is empty. |
| `ra` | Rotate A | `operations_a.c:51` | Shift up all elements of Stack A by 1. The first element becomes the last one. |
| `rb` | Rotate B | `operations_b.c:51` | Shift up all elements of Stack B by 1. The first element becomes the last one. |
| `rr` | Rotate Both | `operations_both.c:22` | Execute `ra` and `rb` simultaneously. |
| `rra` | Reverse Rotate A | `operations_a.c:68` | Shift down all elements of Stack A by 1. The last element becomes the first one. |
| `rrb` | Reverse Rotate B | `operations_b.c:68` | Shift down all elements of Stack B by 1. The last element becomes the first one. |
| `rrr` | Reverse Rotate Both | `operations_both.c:29` | Execute `rra` and `rrb` simultaneously. |

---

## 3. Operational Mechanics in Array-Backed Stacks

In this codebase, stacks are implemented as **contiguous dynamic arrays** where index `0` represents the top of the stack.

### 1. Swap Operations (`sa`, `sb`, `ss`)
```c
void sa(int *stack_a, int p)
{
    int temp;

    temp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = temp;
    if (p == 1)
        write(1, "sa\n", 3);
}
```
- **State Transition**: `[x0, x1, x2, ...]` $\to$ `[x1, x0, x2, ...]`.
- **Complexity**: $O(1)$ constant time exchange.

---

### 2. Push Operations (`pa`, `pb`)
```c
void pa(t_stack *stack, t_size *size)
{
    int i;
    int position_a;

    if (!size->b)
        exit(1);
    i = 0;
    position_a = size->a;
    while (position_a >= 0)
    {
        stack->a[position_a + 1] = stack->a[position_a];
        position_a--;
    }
    size->a++;
    stack->a[0] = stack->b[0];
    while (i < size->b)
    {
        stack->b[i] = stack->b[i + 1];
        i++;
    }
    size->b--;
    write(1, "pa\n", 3);
}
```
- **State Transition (`pa`)**:
  - Stack A: `[a0, a1, ...]` $\to$ `[b0, a0, a1, ...]`.
  - Stack B: `[b0, b1, ...]` $\to$ `[b1, ...]`.
- **Shift Behavior**:
  1. Shifts Stack A elements to the right by 1 to make room at index 0.
  2. Sets `stack->a[0] = stack->b[0]`.
  3. Shifts Stack B elements to the left by 1 to discard the pushed element.
- **Complexity**: $O(N_A + N_B)$.

---

### 3. Rotate Operations (`ra`, `rb`, `rr`)
```c
void ra(int *stack_a, int size_a, int p)
{
    int i;
    int temp;

    i = 0;
    temp = stack_a[0];
    while (i < size_a)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    stack_a[i - 1] = temp;
    if (p == 1)
        write(1, "ra\n", 3);
}
```
- **State Transition**: `[x0, x1, x2, x3]` $\to$ `[x1, x2, x3, x0]`.
- **Shift Behavior**:
  1. Stores `x0` in a temporary variable.
  2. Shifts all subsequent elements left by 1 position.
  3. Replaces the tail element with `x0`.
- **Complexity**: $O(N)$.

---

### 4. Reverse Rotate Operations (`rra`, `rrb`, `rrr`)
```c
void rra(int *stack_a, int size_a, int p)
{
    int i;
    int temp;

    i = size_a - 1;
    temp = stack_a[i];
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[0] = temp;
    if (p == 1)
        write(1, "rra\n", 4);
}
```
- **State Transition**: `[x0, x1, x2, x3]` $\to$ `[x3, x0, x1, x2]`.
- **Shift Behavior**:
  1. Stores the bottom element `x3` in a temporary variable.
  2. Shifts elements right by 1 position starting from the bottom.
  3. Places `x3` at index 0.
- **Complexity**: $O(N)$.

---

## 4. Combined Operations Implementation

The combined operations (`ss`, `rr`, `rrr`) call the individual stack routines with printing disabled (`p = 0`) and emit a single combined instruction:

```c
void ss(int *stack_a, int *stack_b)
{
    sa(stack_a, 0);
    sb(stack_b, 0);
    write(1, "ss\n", 3);
}

void rr(t_stack *stack, t_size *size)
{
    ra(stack->a, size->a, 0);
    rb(stack->b, size->b, 0);
    write(1, "rr\n", 3);
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    rra(stack_a, size_a, 0);
    rrb(stack_b, size_b, 0);
    write(1, "rrr\n", 4);
}
```
This design avoids code duplication while adhering to the 42 output requirement of printing only `ss`, `rr`, or `rrr` without intermediate single-stack logs.
