"""Solution of the task."""


class chain_sum(int):
    def __call__(self, number: int = 0):
        return chain_sum(self + number)


def main() -> None:
    print(chain_sum(5)())  # 5
    print(chain_sum(5)(2)())  # 7
    print(chain_sum(5)(100)(-10)())  # 95


if __name__ == '__main__':
    main()
