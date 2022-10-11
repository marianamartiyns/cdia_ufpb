# Diferença entre a população de X e Y.

x = 70000
y = 180000
c = 0

while x < y:
    
    somax = x * 0.035
    somay = y * 0.015
    
    c = c + 1
    
    x = x + somax
    y = y  + somay

    
print(f"\nSão necessários {c} anos para que a população de x se iguale ou passe a de y.")