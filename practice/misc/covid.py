'''
This is my take on predicting covid cases and estimating herd immunity date.
Note:
* Recovered can be more than total population because it includes re-infections
* Also assumes that there are no lockdowns to slow down the infection
'''
import math

# tested for 23 APR 2021 using public available data for india
TOTAL = 1_300_000_000 # population
HERD_THRESHOLD = 0.75 # herd immunity threshold 75%
CYCLE = 12 # after this patient will either recover or die
FATALITY = .015 # 1.5%
RECOVERED = 14_000_000 # currently recovered
DEAD = 190_000 # currently dead
CURRENT = 2_600_000 # currently active cases
VACCINATED = 127_129_113 # it only effects death count
VACCINATION_PER_DAY = 2_000_000
MULTIPLIER = 1.1 # current effective R0 = cases on day x / cases on day x - 1

# TOTAL = 1_300_000_000
# HERD_THRESHOLD = 0.75
# CYCLE = 12 # days
# FATALITY = .015 # 1.5%
# RECOVERED = 20_000_000
# DEAD = 300_000
# CURRENT = 6_000_000
# MULTIPLIER = 1.2

# -------------------------------------------------------
t_n13 = CURRENT * (MULTIPLIER - 1) / (MULTIPLIER**(CYCLE+1) - 1)
active = [int(t_n13*(MULTIPLIER**i)) for i in range(CYCLE+1)]
print(f'Active case for last {CYCLE+1} days')
print(active)
print(f' Day |   new cases |      deaths |   recovered | multiplier | fatality')
print(f' {0:3d} | {active[-1]:11,} | {DEAD:11,} | {RECOVERED:11,} | {MULTIPLIER:5.3f} | {FATALITY:5.3f}')
days, dead_c, cases_c, r0_c = 0, [], active.copy(), [MULTIPLIER]
while days < 99:
    VACCINATED = min(TOTAL - DEAD, VACCINATED)
    effective_fatality = FATALITY * (1 - VACCINATED / (TOTAL - DEAD))
    VACCINATED += VACCINATION_PER_DAY
    dead_c.append(int(active[0] * effective_fatality))
    DEAD += dead_c[-1]
    RECOVERED += active[0] - dead_c[-1]
    effective_multiplier = MULTIPLIER / math.log(math.e + (RECOVERED + sum(active)) / (TOTAL - DEAD))
    r0_c.append(effective_multiplier)
    new_cases = int(active[-1] * effective_multiplier)
    active.pop(0)
    active.append(new_cases)
    days += 1
    herd = '*' if RECOVERED >= (TOTAL - DEAD) * HERD_THRESHOLD else ' '
    print(f'{herd}{days:3d} | {new_cases:11,} | {DEAD:11,} | {RECOVERED:11,} | {effective_multiplier:5.3f} | {effective_fatality:5.3f}')
