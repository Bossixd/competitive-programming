for i in range(2250, 2350 + 1):
    print(f"{i} / 25  = {int(i / 25) % 9}")
    print(f"{i} % 25  = {i % 25}")
    print(f"{i} % 225 = {i % 225}")
    print()

for i in range(1, 11):
    print(225 * i)