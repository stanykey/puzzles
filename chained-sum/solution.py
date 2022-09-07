"""Solution of the task."""


def chain_sum(value: int):
    class Chain:
        def __init__(self, init: int):
            self._value = init

        def __call__(self, number=None):
            if number is None:
                return self._value
            self._value += number
            return self

    return Chain(value)


def main() -> None:
    print(chain_sum(5)())  # 5
    print(chain_sum(5)(2)())  # 7
    print(chain_sum(5)(100)(-10)())  # 95


if __name__ == '__main__':
    main()
