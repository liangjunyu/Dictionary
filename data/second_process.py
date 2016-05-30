# make_dictionary.py
input = open('firststep', 'r')
output = open('secondstep', 'w')
for line in input.readlines():
	line = line.rstrip('\n')
	line = line.replace("\');", "")
	line = line.replace("/", " ")
	output.write(line+'\n')