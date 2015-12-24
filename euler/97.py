MOD = 10 ** 10;

def pow_mod(n, exp, mod):
    result = 1
    tmp = n % mod
    shift = 0
    while True:
        k = (1 << shift)
        if k > exp:
            break
        if k & exp:
            result = (result * tmp) % mod
        tmp = (tmp * tmp) % mod

        shift += 1
    return result;

print (28433 * pow_mod(2, 7830457, MOD) + 1) % MOD
