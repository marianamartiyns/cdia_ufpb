function matrix_power(x, y, k)
    
    n = length(x)
    
    # Verifica se x e y têm o mesmo tamanho
    if length(y) != n
        throw(ArgumentError("Os vetores x e y devem ter o mesmo tamanho"))
    end
    
    # Calcula xy^T
    xyT = x * y'
    
    # Inicializa a matriz resultante como a matriz de identidade
    result = Matrix{Float64}(I, n, n)
    
    # Calcula (xy^T)^k usando multiplicação de matrizes
    for _ in 1:k
        result *= xyT
    end
    
    return result
end

# Exemplo de uso
x = [1, 2, 3]
y = [4, 5, 6]
k = 2
result = matrix_power(x, y, k)
println(result)
