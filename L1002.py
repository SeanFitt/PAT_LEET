
from ast import List

def commonChars(self, words: List[str]) -> List[str]:
    counter=[words.__len__]*26
    res=''
    for i in range(words.__len__()):
        for j in range(words[i].__len__()):
            counter[i][int(words[i][j])-int('a')]+=1
    for i in range(26):
        letter_counter=min(counter[:,i])
        if letter_counter>0:
            for j in range(letter_counter):
                res.append(chr(i+'a'))
    return res