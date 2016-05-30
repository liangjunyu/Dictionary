# word_to_sentence.py
input = open("firststep", "r")
all_line = input.readlines()
for i in range(len(all_line)):
	if(i%4==0):
	    output = open("worddata/"+all_line[i].rstrip("\n")+".dat", "w")
	    output.write("0\n"+all_line[i])