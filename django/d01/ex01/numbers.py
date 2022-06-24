def solution():
    fr = open("numbers.txt", "r")
    line = fr.readline()
    lst = line.split(',')
    for num in lst:
        print(num)
    fr.close()

if __name__ == '__main__':
    solution()