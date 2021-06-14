bil = int(input())
if (bil <= 0):
    print("bukan prima")
elif (bil == 1):
    print(1)
else:
    for angka in range(1, bil + 1):
        if angka > 0:
            for i in range(2,angka):
                if (angka % i) == 0:
                    break
            else:
                print(str(angka) + str(", "),end='')

