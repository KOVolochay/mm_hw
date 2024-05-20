def hamming(num, dist):
    if dist == 0:
        return [num]
    else:
        outputlist = list()
        for item in range(len(num)):
            if len(num[item:]) > dist - 1:
                if num[item] == "0":
                    restoflist = hamming(num[item + 1:], dist - 1)
                    outputlist.extend(map(lambda x: num[:item] + "1" + x, restoflist))
                else:
                    restoflist = hamming(num[item + 1:], dist - 1)
                    outputlist.extend(map(lambda x: num[:item] + "0" + x, restoflist))
        return outputlist

a = str(input())
n = int(input())
print(hamming(a, n))
