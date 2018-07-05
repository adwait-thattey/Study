import csv
f=open("employee_work_hours.csv","r")
r=csv.reader(f)
l=list(r)
s=0
print("employee-wise total working hours\n")
for employ in range(10001,10011):
    s=0
    print("\nEmploy ID:",employ)
    for i in range(0,126):
        if not l[i]:
            continue
        else:
            if int(l[i][1])==employ:
                print("date(y/m/d):",int(l[i][0]),"Product:",l[i][2],"\tNo.of hours:",int(l[i][3]))
                s=s+int(l[i][3])
    print("total working hours:",s,"\n")
print("---------------------------------------------------------------")
print("Product wise total working hours")
print("\nproduct 1:")
s=0
for i in range(0,126):
    if not l[i]:
        continue
    else:
        if l[i][2] == " P001":
            s = s+int(l[i][3])
print("total working hours:",s,"\n")
print("\nproduct 2:")
s=0
for i in range(0,126):
    if not l[i]:
        continue
    else:
        if l[i][2] == " P002":
            s = s+int(l[i][3])
print("total working hours:",s,"\n")
print("\nproduct 3:")
s=0
for i in range(0,126):
    if not l[i]:
        continue
    else:
        if l[i][2] == " P003":
            s = s+int(l[i][3])
print("total working hours:",s,"\n")
print("\nproduct 4:")
s=0
for i in range(0,126):
    if not l[i]:
        continue
    else:
        if l[i][2] == " P004":
            s = s+int(l[i][3])
print("total working hours:",s,"\n")
print("\nproduct 5:")
s=0
for i in range(0,126):
    if not l[i]:
        continue
    else:
        if l[i][2] == " P005":
            s = s+int(l[i][3])
print("total working hours:",s,"\n")

            

f.close()
