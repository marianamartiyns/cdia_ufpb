function trocar_linhas!(A, i, j)
    # Verifica se i e j são válidos
    if i < 1 || i > size(A, 1) || j < 1 || j > size(A, 1)
        throw(ArgumentError("Índices de linha i e j fora do intervalo válido"))
    end
    
    # Troca as linhas i e j
    A[i, :], A[j, :] = A[j, :], A[i, :]
end

# Exemplo de uso
n = 4  # Tamanho da matriz
A = [1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16]  # Matriz de exemplo
i = 2  # Índice da primeira linha a ser trocada
j = 4  # Índice da segunda linha a ser trocada

println("Matriz A original:")
println(A)

# Trocar as linhas i e j
trocar_linhas!(A, i, j)

println("\nMatriz A após a troca das linhas $i e $j:")
println(A)
