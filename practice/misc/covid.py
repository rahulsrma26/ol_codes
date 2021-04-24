import math

# tested for 23 APR 2021 using public available data for india
TOTAL = 1_300_000_000 # population
HERD_THRESHOLD = 0.75 # herd immunity threshold 75%
CYCLE = 12 # after this patient will either recover or die
FATALITY = .015 # 1.5%
RECOVERED = 14_000_000 # currently recovered
DEAD = 190_000 # currently dead
CURRENT = 2_600_000 # currently active cases
R0 = 1.1 # current effective R0 = cases on day x / cases on day x - 1
# -------------------------------------------------------
t_n13 = CURRENT * (R0 - 1) / (R0**(CYCLE+1) - 1)
active = [int(t_n13*(R0**i)) for i in range(CYCLE+1)]
print(f'Active case for last {CYCLE+1} days')
print(active)
print(f' Day |   new cases |      deaths |   recovered | effective R0 ')
print(f' {0:3d} | {active[-1]:11,} | {DEAD:11,} | {RECOVERED:11,} | {R0:.3f}')
days, dead_c, cases_c, r0_c = 0, [], active.copy(), [R0]
while days < 100 or RECOVERED < (TOTAL - DEAD) * HERD_THRESHOLD:
    dead_c.append(int(active[0] * FATALITY))
    DEAD += dead_c[-1]
    RECOVERED += active[0] - dead_c[-1]
    effective_r0 = R0 / math.log(math.e + (RECOVERED + DEAD + sum(active)) / TOTAL)
    r0_c.append(effective_r0)
    new_cases = int(active[-1] * effective_r0)
    active.pop(0)
    active.append(new_cases)
    days += 1
    herd = '*' if RECOVERED >= (TOTAL - DEAD) * HERD_THRESHOLD else ' '
    print(f'{herd}{days:3d} | {new_cases:11,} | {DEAD:11,} | {RECOVERED:11,} | {effective_r0:.3f}')
