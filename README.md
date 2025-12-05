# MyStack (array-based stack in C)

This repository contains a simple array-based stack implementation in C: `MyStack.c`.

**Files**
- `MyStack.c`: interactive console program implementing a stack with a fixed-size array and a simple menu to push/pop/peek/print.

**Build**
Compile with `gcc`:

```bash
gcc MyStack.c -o MyStack
```

**Run**

```bash
./MyStack
```

The program shows a menu with options:
- `1` print stack
- `2` stack size
- `3` push element in stack
- `4` pop
- `5` peek
- `6` Exit

Type the option number and press Enter. For push, you'll be prompted to enter an integer value.

**Code review & notes**

Summary: `MyStack.c` implements the basic stack operations correctly for normal cases, but contains a few issues and opportunities for improvement. Below are the items found while reviewing the code and recommended fixes.

- **Use `STACK_LEN` consistently**: The code defines `#define STACK_LEN 5` but declares `int arr[5] = {0};`. Replace the `5` with `STACK_LEN` to keep the definition single-sourced.
- **Predicate return values are inverted / non-idiomatic**: `IsStackEmpmty()` and `IsStackFull()` return `0` for true and `-1` for false. This works with the current checks but is confusing. Prefer returning `1` for true and `0` for false (or use `bool` from `stdbool.h`).
- **Typo in function name**: `IsStackEmpmty()` has a typo; rename to `IsStackEmpty()` for clarity.
- **`peek()` lacks bounds check**: `peek()` directly accesses `arr[top]` without checking if the stack is empty — this can read out-of-bounds when `top == -1`. Add an empty check before printing.
- **`pop()` uses inverted check**: `pop()` checks `IsStackEmpmty() == 0` to detect empty; this matches the current return convention but is confusing. After fixing predicate returns, update checks accordingly.
- **Unused/unclear variables**: `char buff[10]` is declared but never used; remove it.
- **Input validation**: `scanf` calls don't check the return value. Consider validating user input to avoid undefined behavior on non-integer input.
- **Magic strings/typos in UI**: menu prints have typos (`stact`, `poping`) — fix text for user friendliness.
- **Prefer returning status from operations**: `push()` and `pop()` could return an int status code indicating success/failure, which is useful for testing.
- **Avoid globals for larger projects**: `arr` and `top` are globals. For this small program that's acceptable, but consider wrapping the stack in a struct for reusability.

Suggested minimal fixes to make the program safer and clearer:

- Change `int arr[5] = {0};` to `int arr[STACK_LEN] = {0};`.
- Rename `IsStackEmpmty()` to `IsStackEmpty()` and make it return `1` when empty and `0` when not empty (or return `bool`). Update all call sites accordingly.
- Add an emptiness check in `peek()` and `pop()` before accessing `arr[top]`.
- Remove `buff[10]` if not used.
- Check `scanf` return values and flush the input buffer on invalid input.

Example quick fix for `peek()` (conceptual):

```c
void peek()
{
    if (IsStackEmpty()) {
        printf("\nstack is empty\n");
        return;
    }
    printf("peek = %d\n", arr[top]);
}
```

**License & attribution**
This is a small learning/demo project; add a license file if you want to reuse or publish it.

If you'd like, I can also:
- Apply the code fixes above and produce a cleaned-up `MyStack.c` (prefer `stdbool.h`, return status codes, input validation).
- Add unit tests or a small non-interactive test harness.

---
Generated on 2025-12-05 — quick code review included.
# datastructurescode
Practice Code of Data Structures
