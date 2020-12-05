import sys, re

l = []

if __name__ == "__main__":
    for param in sys.argv[1:]:
        l.append(param)
        

f = open(l[0], 'r')
lis = [int(line.strip()) for line in f if re.findall(r'-?\d+', line.strip()) != []]
lis = [int(i) for i in lis]

f.close()
w = open(l[1], 'w')
num = sum(lis)
#num %= 256
w.write(str(num))

w.close()
