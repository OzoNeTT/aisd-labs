import re, timeit


a=[]
count = 0
while True:
    
    try:
        s= input()
        if(s==''):
    	    if count ==10:
    		    break
    	    count+=1
        x = [int(i) for i in re.findall(r'-?\d+', s)]
    except (EOFError):
        break 
   
    a+=x

print(sum(a))
