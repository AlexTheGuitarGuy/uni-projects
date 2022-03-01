import string

plain_text = 'iaibal blea'
shift = 7
shift %= 26

alphabet = 'huinea blea'
shifted = alphabet[:shift] + alphabet[shift:]
print(shifted)
