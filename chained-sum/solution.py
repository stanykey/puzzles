"""Solution of the task."""


def chain_sum(init):
    values = [init]

    def chain(*args):
        if args:
            values.extend(args)
            return chain
        return sum(values)
    return chain


def main() -> None:
    print(chain_sum(5)())  # 5
    print(chain_sum(5)(2)())  # 7
    print(chain_sum(5)(100)(-10)())  # 95


if __name__ == '__main__':
    main()
