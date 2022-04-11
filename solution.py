"""Solution of the task."""


class Tree:
    def __init__(self, tiers: int):
        self._data = self._create_tree_data(tiers)

    @property
    def width(self) -> int:
        return len(self._data[0])

    @property
    def height(self) -> int:
        return len(self._data)

    @property
    def data(self) -> list[str]:
        return self._data

    def append_air_lines(self, amount: int):
        if not amount:
            return

        new_data: list[str] = [' ' * self.width] * amount
        new_data.extend(self._data)
        self._data = new_data

    @staticmethod
    def _create_tree_data(tiers: int) -> list[str]:
        data: list[str] = []

        current_tier = ['*']
        for i in range(0, tiers):
            current_tier.append(current_tier[-1] + '**')
            data.extend(current_tier)

        max_stars_count = len(data[-1])
        data = [f'{line: ^{max_stars_count}}' for line in data]
        return data


def print_forest(*args: int) -> str:
    trees = [Tree(tiers) for tiers in args]
    max_height = max(trees, key=lambda item: item.height).height
    for tree in trees:
        tree.append_air_lines(max_height - tree.height)

    image_rows: list[str] = []
    for i in range(0, max_height):
        image_rows.append(''.join(tree.data[i] for tree in trees))

    return '\n'.join(image_rows)
