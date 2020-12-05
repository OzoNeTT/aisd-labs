def permutations(xs):
    ac = [[]]
    for x in xs:
        ac_new = []
        for ts in ac:
            for n in range(0,ts.__len__()+1):
                new_ts = ts[:]  
                new_ts.insert(n,x)
                
                perm = new_ts[:]
                perm.sort() 
                if perm == new_ts:
                    ac_new.append(new_ts)
        ac=ac_new
    return ac
 

for i in permutations([k for k in input().split(" ")]): print(i, end='\n')
