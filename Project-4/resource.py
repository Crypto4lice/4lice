resource = []
rsc = open("./resource.txt", "r")
readhead = rsc.readline()
readhead = readhead.split(' ')

for line in rsc:
    splitine = line.split(',')
    dict = {}
    dict[readhead[0]] = splitine[0]
    dict[readhead[1]] = splitine[1]
    dict[readhead[2]] = splitine[2]
    dict[readhead[3]] = splitine[3]
    resource.append(dict)

com = input("Enter a search string : ")
find = 0
print("Results : ")
print("Name                  | Position          | Separation Date")
print("-----------------------------------------------------------")
for item in resource:
    for var in item.values():
        for i in range(len(var)):
           if com in var:
               print(item.get("FirstName").ljust(10), item.get("LastName").ljust(12), item.get("Position").ljust(20), item.get("SeparationDate\n"))
               find = 1
               break
        if find == 1 :
            break
    find = 0