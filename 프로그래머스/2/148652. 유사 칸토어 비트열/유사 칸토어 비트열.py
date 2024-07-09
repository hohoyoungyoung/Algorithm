def count_ones(n, l, r):
    if n == 0:
        return 1 if l <= 1 <= r else 0

    segment_length = 5 ** (n - 1)
    ones_count = 0

    for i in range(5):
        start = i * segment_length + 1
        end = (i + 1) * segment_length


        if start > r or end < l:
            continue

        if i == 2:
            continue


        new_l = max(l, start) - start + 1
        new_r = min(r, end) - start + 1
        ones_count += count_ones(n - 1, new_l, new_r)

    return ones_count

def solution(n, l, r):
    return count_ones(n, l, r)
