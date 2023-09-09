function multiply_column_by_c!(A, j, c)

    # Verifica se j está dentro dos limites da matriz
    if j < 1 || j > size(A, 2)
        throw(ArgumentError("Índice de coluna j fora dos limites da matriz"))
    end
    
    # Multiplica todos os elementos da coluna j por c
    for i in 1:size(A, 1)
        A[i, j] *= c
    end
end

# Exemplo de uso
n = 3
A = [1.0 2.0 3.0; 4.0 5.0 6.0; 7.0 8.0 9.0]
j = 2  # Coluna que desejamos multiplicar
c = 2.0  # Escalar pelo qual queremos multiplicar

# Chamando a função para multiplicar a coluna j por c
multiply_column_by_c!(A, j, c)

println(A)
