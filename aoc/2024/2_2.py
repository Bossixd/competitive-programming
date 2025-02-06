def check(spl):
    if (spl[1] - spl[0] > 0):
        inc = 1
    else:
        inc = -1
    last = spl[0]
    safee = True
    
    for idx, j in enumerate(spl[1:]):
        error = idx
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
    return safee, error - 1

safe = 0
for i in range(1000):
    s = input()
    spl = list(map(int, s.split()))
    
    safee, error = check(spl)
    if not safee:
        safee, _ = check(spl[:error] + spl[error + 1:])
        error = error + 1
        
    if not safee:
        safee, _ = check(spl[:error] + spl[error + 1:])
        error = error + 1
        
    if not safee:
        safee, _ = check(spl[:error] + spl[error + 1:])
        
    if not safee:
        safee, _ = check(spl[:-1])
    
    if safee:
        safe += 1
        continue
print(safe)