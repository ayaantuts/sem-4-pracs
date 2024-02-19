# To implement the non-restoring division algorithm
# Ayaan Shaikh - C026 - 12 Feb 2024
n = 4

def tobin(num:int, n_bits=n):
    """A function that returns the bit representation of a number in desired number of bits (default = 4)"""
    return bin(num)[2:].zfill(n_bits) if num >= 0 else bin((1 << n_bits) - (-num))[2:]

def twoc(bits:str, n_bits=n):
    """A function that returns the two's complement representation in desired number of bits"""
    return tobin((1 << n_bits) - int(bits, 2))

def left_shift(A:str, Q:str):
    """A function that performs left shift operation and returns A and Q"""
    return A[1:] + Q[0], Q[1:] + '0'

def add(A:str, M:str):
    """A function that performs addition operation on A and Q, neglecting the carry, if any, and returns the sum"""
    S = tobin(int(A, 2) + int(M, 2))
    n_bits = globals()["n"] + 1
    if len(S) > n_bits:
        S = S[1:]
    return S

def division(Q:int, M:int):
    """The non restoring division function"""
    n_bits:int = globals()["n"] + 1
    Q = tobin(Q)
    M = tobin(M, n_bits)
    # M2 is the two's complement of M
    M2 = twoc(M, n_bits)
    A = '0' * n_bits
    count:int = globals()["n"]
    print("n\tA\tQ\tAction")
    action = "Initialize"
    print(count,A, Q, action, sep='\t')
    while count > 0:
        A, Q = left_shift(A, Q)
        action = "Left Shift"
        print(count,A, Q, action, sep='\t')
        if A[0] == "0":
            action = "A = A - M"
            A = add(A, M2)
        else:
            action = "A = A + M"
            A = add(A, M)
        print(count,A, Q, action, sep='\t')
        if A[0] == '1':
            action = "A < 0, Q[0] = 0"
            Q = Q[:-1] + '0'
        else:
            action = "A >= 0, Q[0] = 1"
            Q = Q[:-1] + '1'
        print(count,A, Q, action, sep='\t')
        count -= 1
    if A[0] == "1":
        A = add(A, M)
    print("The quotient =", Q, "=", int(Q, 2), "and the remainder is", A, "=", int(A, 2))

inputText = "Enter a number from less than " + str(2**n) + ": "
x = int(input(inputText))
y = int(input(inputText))
division(x, y)