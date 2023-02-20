import numpy as np

x = [-2, 0, 1, -1, 3]
h = [1, 2, 0, -1]

# Numpy-Implementation
print("\nCall convolution function in numpy.")
print("The correct result is:")
y = np.convolve(x, h, mode="full")
print(y, "\n")

# Self-Implementation
print("The test result through self-implementation is:")

y2 = []
x = dict(enumerate(x))
h = dict(enumerate(h))
for i in range(len(x) + len(h) - 1):
    sum = 0
    for j in range(len(x)):
        sum += x[j] * h.get(i - j, 0)  # Return 0 if the subscript does not exist
    y2.append(sum)

y2 = np.array(y2)
print(y2)

print("\nSuch result is correct!\n")
