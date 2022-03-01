import numpy as np
import random


def playfair(
        text: str,
        key: str,
        alphabet='AĂÂBCDEFGHIÎKLMNOPQRSȘTȚUVWXYZ',
        obfuscation='QVXZ',
        encrypt=True,
):
    def checkValidity():
        try:
            for i in text:
                alphabet.index(i)
            for i in key:
                alphabet.index(i)
        except ValueError:
            print(
                'textul si cheia trebuie sa fie compuse doar din litere ale alfabetului roman.')
            quit()

        if len(key) < 7:
            print('cheia este prea mica, sunt necesare cel putin 7 caractere.')
            quit()

    def processKey():
        res = ''.join(dict.fromkeys(key + alphabet))
        res = np.array(list(res))
        res = np.reshape(res, (5, 6))
        return res

    checkValidity()
    key = processKey()

    if encrypt:
        prev = ''

        def obfuscatingChar():
            nonlocal prev
            res = ''
            res = obfuscation[random.randint(0, len(obfuscation) - 1)]
            while res == prev:
                res = obfuscation[random.randint(0, len(obfuscation) - 1)]
            prev = res
            return res

        def processText():

            res = iter(text)
            res = ' '.join(a+b for a, b in zip(res, res))
            if len(text) % 2 != 0:
                res += ' ' + text[len(text) - 1]
                pass

            for i in range(0, len(res)):
                if(res[i] == res[i - 1]):
                    res = res[:i] + obfuscatingChar() + res[i:]
                    res = res.replace(' ', '')
                    isLenOdd = False
                    if len(res) % 2 != 0:
                        isLenOdd = True
                        lastChar = res[len(res) - 1]

                    res = iter(res)
                    res = ' '.join(a+b for a, b in zip(res, res))

                    if isLenOdd:
                        res += ' ' + lastChar
                        isLenOdd = False

            if len(res.replace(' ', '')) % 2 != 0:
                res += obfuscatingChar()
            return res.split()

        text = processText()
    else:
        def processText():
            res = iter(text)
            res = ' '.join(a+b for a, b in zip(res, res))
            return res.split()
        text = processText()

    res = ''

    if encrypt:
        expr = '+'
        loopx = 0
        loopy = 0
    else:
        expr = '-'
        loopx = len(key) - 1
        loopy = len(key[0]) - 1

    for a, b in text:
        a_i = np.where(key == a)
        b_i = np.where(key == b)

        if (b_i[0] == a_i[0]):
            try:
                res += str(key[(a_i[0], eval(str(int(a_i[1])) + expr + '1'))])
            except IndexError:
                res += str(key[(a_i[0], loopy)])
            try:
                res += str(key[(b_i[0], eval(str(int(b_i[1])) + expr + '1'))])
            except IndexError:
                res += str(key[(b_i[0], loopy)])
        elif (b_i[1] == a_i[1]):
            try:
                res += str(key[(eval(str(int(a_i[0])) + expr + '1'), a_i[1])])
            except IndexError:
                res += str(key[(loopx, a_i[1])])
            try:
                res += str(key[(eval(str(int(b_i[0])) + expr + '1'), b_i[1])])
            except IndexError:
                res += str(key[(loopx, b_i[1])])
        else:
            res += str(key[(b_i[0], a_i[1])])
            res += str(key[(a_i[0], b_i[1])])

    res = res.replace('[', '').replace(']', '').replace('\'', '')

    return res


def playfair_encrypt(text, key):
    return playfair(text=text, key=key, encrypt=True)


def playfair_decrypt(text, key):
    return playfair(text=text, key=key, encrypt=False)


def main():
    encrypt = True if input(
        'doriti sa criptati sau decriptati? (1/0) ') == '1' else False
    key = input('cheie: ').upper().replace(' ', '').replace('J', 'I')
    text = input('text: ').upper().replace(' ', '').replace('J', 'I')

    print('rezultat:',
          (playfair_encrypt(text, key)
           if encrypt else
           playfair_decrypt(text, key)))


main()
