# Escreva uma função, denominada cubo(),que receba como parâmetro um número real e retorne o seu cubo. O programa deverá solicitar que o usuário digite um número, chamará a função cubo(),passando por parâmetro o número digitado,e exibirá na saída padrão o valor do seu cubo.

def cubo(n):
    
    result = n**3
    
    return result

print("\n== NÚMERO AO CUBO ==")
num = int(input("Digite um número: "))

print(f"\n{num}³ é {cubo(num)}.")
