def potencia1(n1,n2):
    
    result = n1 ** n2
    
    return result

def potencia2(n1,n2):
    
    # não esta funcionado pq eu nao soubre fazer sem os **
    for i in range(n2):
        result = n1 * n1
        
    return result

print("\n== VALOR N² ==")
fun = (int(input("Existe duas funções que calcula a potência escolha uma 1 ou 2? ")))
base = int(input("\nDigite a base: "))
exp = int(input("Digite o expoente: "))


if fun == 1:
    print(f"\n{base} elevado á {exp} é {potencia1(base, exp)}.")
    
elif fun == 2:
    print(f"\n{base} elevado á {exp} é {potencia2(base,exp)}.")
    
else:
    print("Número Invalído")