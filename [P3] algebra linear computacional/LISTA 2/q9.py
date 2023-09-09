# Elabore um algoritmo que calcule (xyT) k onde x, y ∈ R n e k ≥ 0 é um inteiro.

import numpy as np

def matrix_power(x, y, k):

    n = len(x)
    
    # Verifica se x e y têm o mesmo tamanho
    if len(y) != n:
        raise ValueError("Os vetores x e y devem ter o mesmo tamanho")
    
    # Calcula xy^T 
    xyT = np.outer(x, y) # A função outer() em NumPy é usada para calcular o produto externo de dois vetores, resultando em uma matriz
    
    # Inicializa a matriz resultante como a matriz de identidade
    result = np.eye(n) # A função eye() em NumPy é usada para criar uma matriz de identidade de tamanho n x n
    
    # Calcula (xy^T)^k usando multiplicação de matrizes
    for _ in range(k):

        result = np.dot(result, xyT) # A função dot() em NumPy é usada para calcular o produto escalar de dois arrays. No contexto do algoritmo, estamos usando-a para realizar a multiplicação de matrizes.
    
    return result

# Exemplo de uso
x = np.array([1, 2, 3])
y = np.array([4, 5, 6])
k = 2
result = matrix_power(x, y, k)
print(result)