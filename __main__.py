"""Application to test the implementation of the task."""

from pathlib import Path
from sys import argv

from solution import print_forest


def print_usage() -> None:
    print(f'usage: {__package__} <input-file> <output-file>')


def validate_path(path: str | Path) -> bool:
    if not isinstance(path, Path):
        path = Path(path)
    return path.exists() and path.is_file()


def main() -> None:
    if len(argv) < 2 or not validate_path(argv[1]):
        print_usage()
        return

    with open(argv[1], 'r', encoding='utf-8') as file:
        trees_data = map(int, file.read().strip().split())

    forest_image = print_forest(*trees_data)
    print(forest_image)

    if len(argv) == 3:
        with open(argv[2], 'w', encoding='utf-8') as file:
            file.write(forest_image)


if __name__ == '__main__':
    main()
