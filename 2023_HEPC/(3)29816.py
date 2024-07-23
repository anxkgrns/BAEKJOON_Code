MOD = 10**9 + 7


def power(a,b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif b % 2 == 0:
        return power((a * a), b // 2) % MOD
    else:
        return (power((a * a), b // 2) * a )% MOD

def main():
    k = int(input())
    N = 2023 * k
    result = 0
    # 1~N 중 2023과 서로소가 아닌 수들의 개수 /  7의 배수와 17의 배수의 수 
    p = N // 7 + N // 17 - N // 119

    # 포함과 배제의 원리 
    # 뽑은 모든 숫자의 함이 2023과 서로소가 아닌 경우의 수 2**p
    # 2**N - 2**p
    result = (power(2, N) - power(2, p)) % MOD  
    result = (2**N - 2**(N-p) ) % MOD

    print(result)

if __name__ == "__main__":
    main()
