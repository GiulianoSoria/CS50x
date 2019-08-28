from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""

    cost[i][j] = min(cost[i + 1][j] + 2, cost[i][j + 1] + 2, cost[i + 1][j + 1] + x)
    # TODO
    return [[]]
