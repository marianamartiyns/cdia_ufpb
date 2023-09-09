function matriz_vandermonde(t)
    m = length(t)  # Número de elementos no vetor t
    n = m  # Número de colunas da matriz de Vandermonde
    
    # Inicializa a matriz de Vandermonde com zeros
    V = zeros(Float64, m, n)
    
    # Preenche a matriz de Vandermonde com as potências dos valores em t
    for i in 1:m
        for j in 1:n
            V[i, j] = t[i]^(j-1)
        end
    end
    
    return V
end

# Exemplo de uso
t = [1, 2, 3, 4]  # Vetor de valores t
V = matriz_vandermonde(t)

println("Matriz de Vandermonde:")
println(V)
