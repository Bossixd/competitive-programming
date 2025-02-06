safe = 0
for i in range(1000):
    s = input()
    spl = list(map(int, s.split()))
    if (spl[1] - spl[0] > 0):
        inc = 1
    else:
        inc = -1
    last = spl[0]
    safee = True
    for j in spl[1:]:
        if (inc == 1 and j - last < 0):
            safee = False
            break
        elif (inc == -1 and j - last > 0):
            safee = False
            break
        
        if (not(abs(j - last) >= 1 and abs(j - last) <= 3)):
            safee = False
            break
        last = j
    if (not safee):
        continue
    safe += 1
print(safe)