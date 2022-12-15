def num_extenso(n):
    
    list_9 = ["Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"]

    list_19 = ["Dez", "Onze", "Doze", "Treze", "Catorze", "Quinze", "Desseis", "Dezesete", "Dezoito", "Dezenove"]

    list_dezena = ["Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"]
    
    if n <= 9:
        result = list_9[n-1]
    
    elif 10 <= n <= 19:
        result = list_19[n-10]

    elif 20 <= n <= 99:
        n_str = str(n)
        a = int(n_str[0])
        b = int(n_str[1])
        
        if b == 0:
            result = list_dezena[a-1]
            
        else:    
            result = (f"{list_dezena[a-1]} e {list_9[b-1]}")
        
    else:
        result = "Número Invalído"
        
    return result

print("\n== Número por Extenso ==")
num = int(input("\nDigite um número(de 1 até 99): "))
print(f"O número {num} por extenso é: {num_extenso(num)}.")