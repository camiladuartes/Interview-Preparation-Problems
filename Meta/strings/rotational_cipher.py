import math

def rotationalCipher(input, rotation_factor):
  # ASCII table:
  # numbers : 0-9
  # alphabet: 65-90
    
  output = ""
  for c in input:
    # it's a number
    if c.isnumeric():
      output += str((int(c) + rotation_factor) % 10)
    elif c.isupper():
      alphabet_location = (ord(c) - ord('A') + rotation_factor) % 26
      output += chr(ord('A') + alphabet_location)
    elif c.islower():
      alphabet_location = (ord(c) - ord('a') + rotation_factor) % 26
      output += chr(ord('a') + alphabet_location)
    else:
        output += c
  
  return output

