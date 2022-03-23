from random import randint

PC1 = [57, 49, 41, 33, 25, 17, 9,
       1, 58, 50, 42, 34, 26, 18,
       10, 2, 59, 51, 43, 35, 27,
       19, 11, 3, 60, 52, 44, 36,
       63, 55, 47, 39, 31, 23, 15,
       7, 62, 54, 46, 38, 30, 22,
       14, 6, 61, 53, 45, 37, 29,
       21, 13, 5, 28, 20, 12, 4]


def hexToBin(K1):
    K1 = int(K1, 16)
    K1 = bin(K1).replace('0b', '')

    while len(K1) % 8 != 0:
        K1 = '0' + K1

    return(K1)


def printPC1():
    for i in range(len(PC1)):
        if (i + 1) % 7 == 0:
            print(PC1[i])
        else:
            print(PC1[i], end=' ')


def permutate(K1):
    res = ''
    for i in range(len(PC1)):
        res += K1[PC1[i] - 1]
        print('nr. ordine:', PC1[i], 'bit:', K1[PC1[i] - 1])

    print('\n')
    print('Rezultatul concatenarii bitilor, care sunt si cheia K+:')
    print(res)

    print('\n')
    print('lungime:', len(res), 'biti')


def main():
    print('\n')
    choice = input(
        'doriti sa introduceti cheia sau sa o generati aleatoriu?(1/2) ')

    print('\n')
    if choice == '1':
        K1 = input('introduceti cheia hexadecimala: ').replace(' ', '')
    elif choice == '2':
        K1 = hex(randint(1000000000000000000, 9999999999999999999)
                 ).upper().replace('0X', '')
        print('Cheia generata:')
        print(K1)

    print('\n')
    print('Se transforma din hexadecimal in binar:')
    K1 = hexToBin(K1)
    print(K1)

    print('\n')
    print('Cu ajutorul tabelului PC1:')
    printPC1()

    print('\n')
    print('Se efectueaza operatiile de permutare:')
    permutate(K1)


main()


"""2.1. Fiind dată cheia algoritmului DES (8 simboluri), de determinat K+. 

Sarcina 2. De elaborat un program în unul din limbajele de programare
preferate pentru implementarea unui element al algoritmului DES. Sarcina se
va alege în conformitate cu numărul n de ordine al studentului din lista grupei,
în conformitate cu formula: nr_sarcina = n mod 11. Pentru fiecare sarcină să
fie afișate la ecran tabelele utilizate și toți pașii intermediari. Datele de intrare
să fie posibil de introdus de utilizator sau de generat în mod aleatoriu.
Atenție! La susținerea lucrării vor fi puse întrebări despre lucrul întregului
algoritm!!!"""
