from collections.abc import MutableSequence
from random import randint


def shuffle[T](sequence: MutableSequence[T]) -> MutableSequence[T]:
    for i in range(len(sequence)):
        index = randint(0, i)
        sequence[i], sequence[index] = sequence[index], sequence[i]
    return sequence


def main() -> None:
    print(shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]))
    print(shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]))
    print(shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]))
    print(shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]))
    print(shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]))


if __name__ == '__main__':
    main()
