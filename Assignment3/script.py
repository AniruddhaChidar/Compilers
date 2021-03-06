import os

def foo(mainDirectory):
	os.chdir(mainDirectory)
	files = next(os.walk('.'))[2]
	os.chdir('..')

	for file in files:
		print("---------------------------------------------------------------------------------------------------------")
		print(file + "\n")
		file = mainDirectory + "/" + file;
		print("SCLP")
		os.system("./sclp -ast -tokens -symtab -eval -d " + file + " > sclp.out")
		os.system("./sclp -icode -d " + file + " > sclp1.out")
		print("\nGIVENSCLP")
		os.system("./givensclp -ast -tokens -symtab -eval -d " + file + " > givensclp.out")
		os.system("./givensclp -icode -d " + file + " > givensclp1.out")
		print("\nDIFF\n")
		os.system("diff sclp.out givensclp.out")
		os.system("diff sclp1.out givensclp1.out")
	os.system("rm *.out")
	print("\n")
	print("#########################################################################################################")
	print("#########################################################################################################")
	print("#########################################################################################################")
	print("#########################################################################################################")
	print("\n")

os.system("make")
directories = ["testing", "errorTesting"]
for dir in directories:
	foo(dir)