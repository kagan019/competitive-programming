ifdef problem

CPP = g++
ARGS_KATTIS = \
	-g \
	-ggdb \
	-static \
	-O2 \
	-Wfatal-errors -w \
	${problem} \
	-o a.exe
TEST_FILE = test.txt
RESULT_FILE = result.txt

solution: 
	$(CPP) $(ARGS_KATTIS) 
	a.exe < $(TEST_FILE) > $(RESULT_FILE)
	type $(RESULT_FILE)

endif