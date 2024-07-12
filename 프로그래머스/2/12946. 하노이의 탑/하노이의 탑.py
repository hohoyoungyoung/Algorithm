def solution(n):
 
    order_list = []

    stack = [(n, 1, 3, 2)]

    while stack:
        N, From, To, Sub = stack.pop()
        if N == 1:
            order_list.append([From, To])

        else:
            stack.append((N - 1, Sub, To, From))
            stack.append((1, From, To, Sub))
            stack.append((N - 1, From, Sub, To))

    return order_list
