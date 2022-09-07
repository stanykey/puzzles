"""Solution of the task."""
from functools import partial, wraps
from operator import add, sub, mul, truediv
from typing import Callable


#
# Operations
#
def operation_function(operation: Callable[[int, int], int], value: int) -> Callable[[int], int]:
    @wraps(operation)
    def wrapper(argument: int):
        return operation(argument, value)
    return wrapper


plus = partial(operation_function, add)
minus = partial(operation_function, sub)
times = partial(operation_function, mul)
divided_by = partial(operation_function, truediv)


#
# Numbers
#
def number_function(value: int = 0, operation: Callable[[int], int] = None) -> int:
    if not operation:
        return value
    return int(operation(value))


zero = partial(number_function, 0)
one = partial(number_function, 1)
two = partial(number_function, 2)
three = partial(number_function, 3)
four = partial(number_function, 4)
five = partial(number_function, 5)
six = partial(number_function, 6)
seven = partial(number_function, 7)
eight = partial(number_function, 8)
nine = partial(number_function, 9)


def main() -> None:
    print(seven(times(five())))    # 35
    print(four(plus(nine())))      # 13
    print(eight(minus(three())))   # 5
    print(six(divided_by(two())))  # 3


if __name__ == '__main__':
    main()
