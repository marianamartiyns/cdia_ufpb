function multiply_columns(A, c)
    
    n = size(A, 1)
    m = size(A, 2)
    
    # Verifica se o tamanho de c corresponde ao número de colunas de A
    if length(c) != m
        throw(ArgumentError("O vetor c deve ter o mesmo número de elementos que o número de colunas de A"))
    end
    
    # Multiplica cada coluna de A pelo valor correspondente em c
    for j in 1:m
        A[:, j] *= c[j]
    end
    
    return A
end

# Exemplo de uso
A = [1 2 3; 4 5 6; 7 8 9]
c = [2, 3, 4]
result = multiply_columns(A, c)
println(result)
