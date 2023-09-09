function multiply_column_by_2!(A)

    n = size(A, 1)  # Obtém o tamanho (número de linhas) da matriz A
    for i in 1:n
        A[i, 1] *= 2  # Multiplica o elemento da coluna 1 da linha i por 2
    end
    
end

# Exemplo de uso:
n = 4
A = rand(n, n)  # Crie uma matriz aleatória de tamanho n x n
println("Matriz A original:")
println(A)

# Chame a função para multiplicar por 2 a coluna 1
multiply_column_by_2!(A)

println("\nMatriz A após multiplicar por 2 a coluna 1:")
println(A)
