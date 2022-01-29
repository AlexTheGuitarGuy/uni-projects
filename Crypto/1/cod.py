from asyncore import ExitNow
from audioop import add
import sys

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
latin_alphabet = 'ABCDEFGHIKLMNOPQRSTVXYZ'

def isEnglish(s):
    try:
        s.encode(encoding='utf-8').decode('ascii')
    except UnicodeDecodeError:
        return False
    else:
        return True

def caesarLoop(string_input, op, alphabet_key):
    done = False
    while not done:

        key = int(input("Introduceti cheia(1->25): "))

        if (key > 0 and key < 26):

            string_res = ""

            for i in range(len(string_input)):

                character = string_input[i]
                location_of_character = alphabet_key.find(character)
                new_location = eval(
                    str(location_of_character) + op + str(key)) % 26
                string_res += alphabet_key[new_location]

            done = True
        else:
            print(
                "Valoare invalida, introduceti o cifra intre 1 si 25.")
    print("\nRezultat: \n")
    return string_res


def getValidInput(message):
    while True:
        res = (
            input(message)).upper().replace(' ', '')
        if (isEnglish(res) and res.isalpha()):
            break
        else:
            print(
                "Valoare invalida, introduceti o propozitie ce contine doar litere din intervalele A-Z si a-z.")
    return res


def caesar(op):

    string_input = getValidInput("introduceti o propozitie exclusiv alfabetica: ")

    string_res = caesarLoop(string_input, op, alphabet)

    print(string_res)


def getKey():
    done = False

    while not done:
        user_key = getValidInput("Introduceti o cheie compusa din cel putin 7 litere ale alfabetului latin: ")
        key = ""

        for char in user_key:
            if char in latin_alphabet and len(user_key) >= 7:
                done = True
            else:
                print(
                    "Cheia trebuie sa contina doar litere din alfabetul latin si cel putin 7, introduceti din nou.")
                done = False
                break
    
    for char in user_key:
            if char in alphabet and char not in key:
                key += char

    for char in alphabet:
        if char not in key:
            key += char

    return key


def caesarKey(op):
    string_input = getValidInput("introduceti o propozitie exclusiv alfabetica: ")

    key = getKey()

    print(caesarLoop(string_input, op, key))

def quit():
    print("iesire")
    sys.exit()


def menu():
    print("\n*******Meniul principal*******")

    choice = input("""
    
    1: Cezar encriptare
    2: Cezar decriptare
    3: Cezar + cuvant cheie
    4: Cezar + cuvant cheie
    0: Iesire din meniu

    Alegeti o optiune

    """)
    match (choice):
        case "1":
            caesar('+')
        case "2":
            caesar('-')
        case "3":
            caesarKey('+')
        case "4":
            caesarKey('-')
        case "0":
            quit()
        case _:
            print("alegerea nu este din meniu")
    menu()


menu()
