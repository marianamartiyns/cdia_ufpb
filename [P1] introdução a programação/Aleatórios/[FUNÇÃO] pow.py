# Escreva um programa que leia dois valores inteiros, n1 e n2 , e exiba na tela o valor de n1 elevado a n2. Para isso, você deverá implementar duas versões da função potência(). A primeira versão deverá usar o operador de exponenciação ** e a segunda não. Em ambas as versões, a função terá como parâmetros n1 e n2 e retorna o valor n1 de elevado a n2.
'''
def pow1(n1 , n2):
    
    result = n1 ** n2
    return result

def pow2(n1 , n2):
    
    def multiplicar(x, y): 

        resultado = x 
        for _ in range(y-1): 
            resultado += x
        return resultado
 

    resultado = n1
    for _ in range(n2-1): 
        resultado = multiplicar(resultado, n1)
        
    return resultado 
    

print("\n== VALOR N² ==")
fun = (int(input("Existe duas funções que calcula a potência escolha uma 1 ou 2? ")))
base = int(input("\nDigite a base: "))
exp = int(input("Digite o expoente: "))


if fun == 1:
    print(f"\n{base} elevado á {exp} é {pow1(base, exp)}.")
    
elif fun == 2:
    print(f"\n{base} elevado á {exp} é {pow2(base,exp)}.")
    
else:
    print("Número Invalído")'''
