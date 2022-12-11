# Faça um programa com uma função que converta da notação de 24 horas para anotação de 12 horas. Por exemplo, o programa deve converter 14:25 em 2:25 PM. A entrada é dada em dois inteiros(horas e minutos).

#ajeitar pra aceitar entradas como 14:45

def convertor(num):
    
    if num < 10:
        return '000' + str(num)
    elif num < 100:
        return '00' + str(num)
    elif num < 1000:
        return '0' + str(num)
    else:
        return str(num)

print('24h to 12h Converter')
num = int(input('Answer: '))

normal = 0

if num == 0000:
    normal = '12:00 A.M'
    print(normal)
    
elif num > 1200:
    normal = convertor(num - 1200)
    print(normal[0:2] + ':' + normal[2:] + ' P.M')
    
else:
    normal = convertor(num+1200)
    print(normal[0:2] + ':' + normal[2:] + ' A.M')