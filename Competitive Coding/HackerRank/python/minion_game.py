import re

S = input();
vovels = ['A','E','I','O','U']

def count_substrs():
    """
    @param which: 
        if True, count all starting with vovels.
        if false, count all starting with consonants.
    """
    vov_str_dict = {};
    con_str_dict = {};
    kev = 0
    stu = 0
    for i in range(len(S)):
        if (S[i] in vovels):
            l = 1
            while (l+i) <= len(S):
                substr = S[i:i+l]
                if substr not in vov_str_dict:
                    vov_str_dict[substr]=True;
                    kev += len(re.findall(f'(?={substr})',S))
                l+=1
        
        else:
            l = 1
            while (l+i) <= len(S):
                substr = S[i:i+l]
                if substr not in con_str_dict:
                    con_str_dict[substr]=True;
                    stu += len(re.findall(f'(?={substr})',S))
                l+=1
        
   # print(tot_count)                                    
    return kev, stu


kev_ptr, stu_ptr = count_substrs();

if kev_ptr == stu_ptr:
    print("Draw")

elif kev_ptr > stu_ptr:
    print("Kevin",kev_ptr)

else:
    print("Stuart", stu_ptr)






