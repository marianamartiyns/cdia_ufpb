/*Sistema de Desenho de Pol�gonos

    1) Implementar as classes descritas abaixo em C++
        a. Canvas (Tela de Desenho)
            i. Atributos (tipos entre par�nteses)
                1. Tamanho em pixels (Array contendo valores inteiros para tamanho em pixels da altura e da largura da tela para desenho)
                2. Conjunto de Pol�gonos do Canvas (Array contendo os pol�gonos criados pelo usu�rio)
            ii. M�todos
                1. Recuperar tamanho (retorna Array de inteiros com tamanho em pixels da tela de desenho � largura e altura)
                2. Recuperar pol�gonos do canvas (retorna Array de Pol�gonos)
                3. Exibir pol�gonos (exibe na tela quais pol�gonos pertencem ao canvas)
        b. Pol�gono
            i. Atributos (tipos entre par�nteses)
                1. Coordenadas (x,y) do centro do pol�gono (Array de Inteiros)
                2. Z-Index � coordenada Z para sobreposi��o de pol�gonos (Inteiro)
                3. Cor do pol�gono (String)
            ii. M�todos
                1. Calcular e retornar �rea (retorna Inteiro) � m�todo virtual
                2. Calcular e retornar Per�metro (retorna Inteiro) � m�todo virtual
                3. Retornar centro do pol�gono (retorna Array com valores Inteiros para ponto do centro)
                4. Retornar cor do pol�gono (retorna String)
        c. Ret�ngulo (heran�a p�blica de Pol�gono)
            i. Atributos
                1. Base em pixels (Inteiro)
                2. Altura em pixels (Inteiro)
            ii. M�todos
                1. Calcular e retornar �rea (retorna Inteiro)
                2. Calcular e retornar per�metro (retorna Inteiro)
        d. C�rculo (heran�a p�blica de Pol�gono)
            i. Atributos
                1. Raio (Inteiro)
            ii. M�todos
                1. Calcular e retornar �rea (retorna Inteiro)
                2. Calcular e retornar per�metro (retorna Inteiro)
        e. Mais dois tipos de pol�gonos (ex. Tri�ngulo, Pent�gono, Hex�gono etc.) � escolha do aluno, com atributos e m�todos equivalentes (heran�a p�blica de Pol�gono)

 Implementar um programa em C++ que crie uma inst�ncia da classe Canvas, a partir de informa��es fornecidas pelo usu�rio, e em seguida criar um loop de execu��o que apresente um menu com as op��es apresentadas a seguir, cujas funcionalidades devem ser realizadas quando selecionadas:
        a. Exibir informa��es do canvas (tamanho e quantos pol�gonos possui)
        b. Inserir Ret�ngulo
        c. Inserir C�rculo
        d. Inserir Pol�gono definido pelo Aluno (1)
        e. Inserir Pol�gono definido pelo Aluno (2)
        f. Exibir Pol�gonos na tela (listar pol�gonos e exibir informa��es: tipo, centro, cor, �rea e per�metro)
        g. Eliminar pol�gono pelo �ndice de inser��o (�ndice associado � ordem de cria��o do Pol�gono)
        h. Salvar um arquivo de texto com a lista de pol�gonos do canvas (com as informa��es: tipo, centro, cor, �rea e per�metro).
        i. Sair
Fa�a o programa lan�ar exce��es caso valores exp�rios sejam inseridos; trate as exce��es de forma que o cadastro seja cancelado e se solicite ao usu�rio para que fa�a um novo cadastro.*/
