import sympy as sp

a,b,c,d,e = sp.symbols("a b c d e")
perspective_matrix = sp.ImmutableDenseMatrix([
    [a,0,0,0],
    [0,b,0,0],
    [0,0,c,d],
    [0,0,e,0]
])

print(perspective_matrix)
print(perspective_matrix.inverse())

# Output:
# Matrix([[a, 0, 0, 0], [0, b, 0, 0], [0, 0, c, d], [0, 0, e, 0]])
# Matrix([[1/a, 0, 0, 0], [0, 1/b, 0, 0], [0, 0, 0, 1/e], [0, 0, 1/d, -c/(d*e)]])

