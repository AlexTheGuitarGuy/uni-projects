def vigenere(
        text: str,
        key: str,
        alphabet='AĂÂBCDEFGHIÎJKLMNOPQRSȘTȚUVWXYZ',
        encrypt=True
):
    try:
        for i in text:
            alphabet.index(i)
        for i in key:
            alphabet.index(i)
    except ValueError:
        print(
            'textul si cheia trebuie sa fie compuse doar din litere ale alfabetului roman.')
        return

    if len(key) < 7:
        print('cheia este prea mica, sunt necesare cel putin 7 caractere.')
        return

    result = ''

    for i in range(len(text)):
        letter_n = alphabet.index(text[i])
        key_n = alphabet.index(key[i % len(key)])

        if encrypt:
            value = (letter_n + key_n) % len(alphabet)
        else:
            value = (letter_n - key_n) % len(alphabet)

        result += alphabet[value]

    return result


def vigenere_encrypt(text, key):
    return vigenere(text=text, key=key, encrypt=True)


def vigenere_decrypt(text, key):
    return vigenere(text=text, key=key, encrypt=False)


def main():
    encrypt = True if input(
        'doriti sa criptati sau decriptati? (1/0)') == '1' else False
    key = input('cheie: ').replace(' ', '').upper()
    text = input('text: ').replace(' ', '').upper()

    print('rezultat:',
          vigenere_encrypt(text, key)
          if encrypt else
          vigenere_decrypt(text, key))


main()
