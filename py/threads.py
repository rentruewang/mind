# Copyright (c) RenChu Wang - All Rights Reserved

import time
from multiprocessing import pool


def print_periodically(num: int) -> None:
    while True:
        time.sleep(1)
        print(num)


if __name__ == "__main__":
    p = pool.ThreadPool(2)
    p.map_async(print_periodically, range(2))

    print("here")
    time.sleep(10)
    print("done")
