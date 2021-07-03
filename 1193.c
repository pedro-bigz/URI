import math

def main ():
    n = int (input())
    for i in range(n):
        inp = input().split(" ")
        num = inp[0]
        base = inp[1]
        case = "Case {}:"

        print (case.format(i + 1))

        if base == "bin":
            print(str(binToDec (num)) + " dec")
            print(str(binToHex (num)) + " hex\n")

        elif base == "dec":
            print(str(decToHex (num)) + " hex")
            print(str(decToBin (num)) + " bin\n")

        elif base == "hex":
            print(str(hexToDec (num)) + " dec")
            print(str(hexToBin (num)) + " bin\n")



def binToDec (num):
    result = 0
    j = len(num) - 1
    for i in range(len(num)):
        result += int(num[i]) * 2**j
        j -= 1

    return result


def binToHex (num):
    hex = [0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f']
    n = len(num)
    half = n/4
    g = math.ceil(half)
    r = n % 4
    total = ""
    result = ""

    for j in range(r):
        total += num[j]

    if (len(num) < 4):
        result += str(hex[binToDec(total)])
        total = ""

    for i in range(r, n):
        if i == n - 1:
            total += num[i]
            result += str(hex[binToDec(total)])

        if (not ((i - r) % 4) and i):
            result += str(hex[binToDec(total)])
            total = ""

        total += num[i]
        g -= 1

    return result


def hexToDec (num):
    hex = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'a':10,'b':11,'c':12,'d':13,'e':14,'f':15}
    result = 0
    j = len(num) - 1
    for i in range(len(num)):
        result += hex[num[i]] * 16**j
        j -= 1

    return result


def hexToBin (num):
    return decToBin(hexToDec(num))


def decToBin (num):
    num = int(num)
    binary = ""

    while num:
        binary += str(num % 2)
        num = int(num / 2)

    return binary[::-1]


def decToHex (num):
    return binToHex(decToBin(num))

main ()
