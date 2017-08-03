# varlue for listmap
resource = []
# open file and set listmap's key
rsc = open("./resource.txt", "r")
readhead = rsc.readline()
readhead = readhead.split(' ')

# set listmap
for line in rsc:
    splitine = line.split(',')
    dict = {}
    dict[readhead[0]] = splitine[0]
    dict[readhead[1]] = splitine[1]
    dict[readhead[2]] = splitine[2]
    dict[readhead[3]] = splitine[3]
    resource.append(dict)
# input users command
com = input("Enter a search string : ")
find = 0
print("Results : ")
print("Name                  | Position          | Separation Date")
print("-----------------------------------------------------------")
# searching containing certain word data
for item in resource:
    # listmap -> map -> values
    for var in item.values():
        for i in range(len(var)):
            # compare certain word
            if com in var:
                # if containing print listmap
                print(item.get("FirstName").ljust(10), item.get("LastName").ljust(12), item.get("Position").ljust(20), item.get("SeparationDate\n"))
                # add find flag to avoid overlap
                find = 1
                break
        # if overlap occur -> break out 
        if find == 1 :
            break
    find = 0
