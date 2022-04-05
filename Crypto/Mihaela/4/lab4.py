from random import randint

schedule = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]


def getRandK():
    res = bin(randint(1000000000000000000, 9999999999999999999)
              ).replace('0b', '')
    while len(res) % 8 != 0:
        res = '0' + res
    return res


def printBin(K):
    for i in range(len(K)):
        if (i + 1) % 8 == 0:
            print(K[i], end=' ')
        else:
            print(K[i], end='')


def ISHFTC(n, d, N):
    return ((n << d) % (1 << N)) | (n >> (N - d))


def getCAndD(K):
    print('\n\nSe imparte cheia originala in 2 jumatati:')
    C = K[:len(K)//2]
    D = K[len(K)//2:]
    print('C0:')
    printBin(C)
    print('\n')
    print('D0:')
    printBin(D)
    print('\n')

    print('Apoi, cu ajutorul tabelului permutatiilor:')
    print(schedule)
    print('se efectuaza miscarea circulara spre stanga a cheii, astfel obtinandu-se toate subcheile Ci si Di:')
    for i in range(0, 16):
        C = bin(ISHFTC(int(C, 2), schedule[i], 32)).replace('0b', '')
        while len(C) != 32:
            C = '0' + C
        D = bin(ISHFTC(int(D, 2), schedule[i], 32)).replace('0b', '')
        while len(D) != 32:
            D = '0' + D
        print('\n')
        print('C{}:'.format(i + 1))
        printBin(C)
        print('\n')
        print('D{}:'.format(i + 1))
        printBin(D)


def main():
    print('\n')
    choice = input(
        'doriti sa introduceti cheia sau sa o generati aleatoriu?(1/2) ')

    print('\n')
    if choice == '1':
        K = input('introduceti cheia hexadecimala: ').replace(' ', '')
    elif choice == '2':
        K = getRandK()
        print('Cheia generata:')
        printBin(K)

    getCAndD(K)


main()


"""2.2. Fiind dat K+ în algoritmului DES, de determinat Ci și Di pentru un i dat. 

Sarcina 2. De elaborat un program în unul din limbajele de programare
preferate pentru implementarea unui element al algoritmului DES. Sarcina se
va alege în conformitate cu numărul n de ordine al studentului din lista grupei,
în conformitate cu formula: nr_sarcina = n mod 11. Pentru fiecare sarcină să
fie afișate la ecran tabelele utilizate și toți pașii intermediari. Datele de intrare
să fie posibil de introdus de utilizator sau de generat în mod aleatoriu.
Atenție! La susținerea lucrării vor fi puse întrebări despre lucrul întregului
algoritm!!!"""
