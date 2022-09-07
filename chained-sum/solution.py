"""Solution of the task."""


def chain_sum(init):
    result = init

    def chain(number=None):
        nonlocal result
        if number is None:
            return result

        result += number
        return chain
    return chain


def main() -> None:
    print(chain_sum(5)())  # 5
    print(chain_sum(5)(2)())  # 7
    print(chain_sum(5)(100)(-10)())  # 95


if __name__ == '__main__':
    main()
