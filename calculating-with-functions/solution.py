"""Solution of the task."""
from functools import partial
from operator import add, sub, mul, truediv
from typing import Callable


#
# Operations
#
def _operator(operator: Callable[[int, int], int], rhs: int) -> Callable[[int], int]:
    return lambda lhs: operator(lhs, rhs)


plus = partial(_operator, add)
minus = partial(_operator, sub)
times = partial(_operator, mul)
divided_by = partial(_operator, truediv)


#
# Numbers
#
def _digit(value: int = 0, operation: Callable[[int], int] = None) -> int:
    if not operation:
        return value
    return int(operation(value))


zero = partial(_digit, 0)
one = partial(_digit, 1)
two = partial(_digit, 2)
three = partial(_digit, 3)
four = partial(_digit, 4)
five = partial(_digit, 5)
six = partial(_digit, 6)
seven = partial(_digit, 7)
eight = partial(_digit, 8)
nine = partial(_digit, 9)


def main() -> None:
    print(seven(times(five())))    # 35
    print(four(plus(nine())))      # 13
    print(eight(minus(three())))   # 5
    print(six(divided_by(two())))  # 3


if __name__ == '__main__':
    main()
