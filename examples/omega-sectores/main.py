import sys
import io

def stream_numbers():
    stdin = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    buf = ''
    while True:
        chunk = stdin.read(8192)
        if not chunk:
            if buf:
                yield int(buf)
            break
        for ch in chunk:
            if ch.isspace():
                if buf:
                    yield int(buf)
                    buf = ''
            else:
                buf += ch


def get_min_distance(pos: int, last: int) -> int:
    if pos < last // 2:
        return pos + 1
    else:
        return last - pos

def main():
    stream = stream_numbers()

    ships_no = next(stream)
    sectors_no = next(stream)

    for _ in range(ships_no):
        movs_no = next(stream)
        init_pos = next(stream)

        current_pos = init_pos

        for _ in range(movs_no):
            current_pos += next(stream)

        final_pos = current_pos % sectors_no

        print(f"{final_pos} {get_min_distance(final_pos, sectors_no - 1)} {current_pos}")

if __name__ == "__main__":
    main()