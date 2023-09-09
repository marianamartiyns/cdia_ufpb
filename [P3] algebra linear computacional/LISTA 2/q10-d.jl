function multiply_rows_by_constants(A, constants)
    
    n = size(A, 1)
    
    # Verifica se o tamanho do vetor de constantes coincide com o número de linhas de A
    if length(constants) != n
        throw(ArgumentError("O vetor de constantes deve ter o mesmo tamanho que o número de linhas de A"))
    end
    
    # Multiplica cada linha de A pelos valores correspondentes em constants usando broadcasting
    result = A .* constants
    
    return result
end

# Exemplo de uso
A = [1 2 3; 4 5 6; 7 8 9]
constants = [2.0, 3.0, 4.0]
result = multiply_rows_by_constants(A, constants)
println(result)
