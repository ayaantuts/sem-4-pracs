# To implement booth's multiplication algorithm
# Ayaan Shaikh - C1-1 C026 - 05 Feb 2024

# Change the value of n to change the number of bits
n = 4
print("Booth's Multiplication Algorithm")
print("Ayaan Shaikh - C1-1 C026 - 05 Feb 2024")

def tobin(num:int, n_bits=n):
    """A function that returns the bit representation of a number in desired number of bits (default = 4)"""
    return bin(num)[2:].zfill(n_bits) if num >= 0 else bin((1 << n_bits) - (-num))[2:]

def twoc(bits:str, n_bits=n):
    """A function that returns the two's complement representation in desired number of bits"""
    return tobin((1 << n_bits) - int(bits, 2), n_bits)

def right_shift(A:str, Q:str):
    """A function that performs right shift operation and returns A, Q, Q1"""
    return A[0] + A[:-1], A[-1] + Q[:-1], Q[-1]

def add(A:str, M:str):
    """A function that performs addition operation on A and Q, neglecting the carry, if any, and returns the sum"""
    S = tobin(int(A, 2) + int(M, 2))
    n_bits = globals()["n"]
    if len(S) > n_bits:
        S = S[1:]
    return S

def booths(M:int, Q:int):
    """The multiplying function M is the multiplicand and Q is the multiplier"""
    n_bits:int = globals()["n"]
    Q = tobin(Q)
    # Q1 is the last bit of Q
    Q1 = '0'
    M = tobin(M, n_bits)
    M2 = twoc(M, n_bits)
    A = '0' * n_bits
    count:int = globals()["n"]
    print("n","A","Q","Q1","Action", sep='\t')
    action = "Initialize"
    print(count,A, Q, Q1, action, sep='\t')
    while count > 0:
        if (Q[-1] != Q1):
            if (Q1 == '1'):
                action = "A = A + M"
                A = add(A, M)
            else:
                action = "A = A - M"
                A = add(A, M2)
        print(count,A, Q, Q1, action, sep='\t')
        A, Q, Q1 = right_shift(A, Q)
        action = "Right Shift"
        print(count,A, Q, Q1, action, sep='\t')
        count -= 1
    result = A + Q
    neg = 0
    """Check if the result is negative, by checking the MSB"""
    if (result[0] == '1'):
        neg = 1
        result = twoc(result, 2 * n_bits)
    print("Answer =", result)
    print("Numerical answer:", -int(result, 2) if neg else int(result, 2))

inputText = "Enter a number from " + str(-2**(n - 1)) + " to " + str(2**(n - 1) - 1) + ": "
x = int(input(inputText))
y = int(input(inputText))
booths(x, y)