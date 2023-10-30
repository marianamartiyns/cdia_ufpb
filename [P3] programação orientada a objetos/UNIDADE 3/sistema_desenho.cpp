/*Sistema de Desenho de Polígonos

    1) Implementar as classes descritas abaixo em C++
        a. Canvas (Tela de Desenho)
            i. Atributos (tipos entre parênteses)
                1. Tamanho em pixels (Array contendo valores inteiros para tamanho em pixels da altura e da largura da tela para desenho)
                2. Conjunto de Polígonos do Canvas (Array contendo os polígonos criados pelo usuário)
            ii. Métodos
                1. Recuperar tamanho (retorna Array de inteiros com tamanho em pixels da tela de desenho – largura e altura)
                2. Recuperar polígonos do canvas (retorna Array de Polígonos)
                3. Exibir polígonos (exibe na tela quais polígonos pertencem ao canvas)
        b. Polígono
            i. Atributos (tipos entre parênteses)
                1. Coordenadas (x,y) do centro do polígono (Array de Inteiros)
                2. Z-Index – coordenada Z para sobreposição de polígonos (Inteiro)
                3. Cor do polígono (String)
            ii. Métodos
                1. Calcular e retornar Área (retorna Inteiro) – método virtual
                2. Calcular e retornar Perímetro (retorna Inteiro) – método virtual
                3. Retornar centro do polígono (retorna Array com valores Inteiros para ponto do centro)
                4. Retornar cor do polígono (retorna String)
        c. Retângulo (herança pública de Polígono)
            i. Atributos
                1. Base em pixels (Inteiro)
                2. Altura em pixels (Inteiro)
            ii. Métodos
                1. Calcular e retornar área (retorna Inteiro)
                2. Calcular e retornar perímetro (retorna Inteiro)
        d. Círculo (herança pública de Polígono)
            i. Atributos
                1. Raio (Inteiro)
            ii. Métodos
                1. Calcular e retornar área (retorna Inteiro)
                2. Calcular e retornar perímetro (retorna Inteiro)
        e. Mais dois tipos de polígonos (ex. Triângulo, Pentágono, Hexágono etc.) à escolha do aluno, com atributos e métodos equivalentes (herança pública de Polígono)

 Implementar um programa em C++ que crie uma instância da classe Canvas, a partir de informações fornecidas pelo usuário, e em seguida criar um loop de execução que apresente um menu com as opções apresentadas a seguir, cujas funcionalidades devem ser realizadas quando selecionadas:
        a. Exibir informações do canvas (tamanho e quantos polígonos possui)
        b. Inserir Retângulo
        c. Inserir Círculo
        d. Inserir Polígono definido pelo Aluno (1)
        e. Inserir Polígono definido pelo Aluno (2)
        f. Exibir Polígonos na tela (listar polígonos e exibir informações: tipo, centro, cor, área e perímetro)
        g. Eliminar polígono pelo índice de inserção (índice associado à ordem de criação do Polígono)
        h. Salvar um arquivo de texto com a lista de polígonos do canvas (com as informações: tipo, centro, cor, área e perímetro).
        i. Sair
Faça o programa lançar exceções caso valores expúrios sejam inseridos; trate as exceções de forma que o cadastro seja cancelado e se solicite ao usuário para que faça um novo cadastro.*/
