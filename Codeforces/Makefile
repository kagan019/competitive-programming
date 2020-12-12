ifdef problem

CPP = g++
ARGS_CODEFORCES = \
	-g \
    -ggdb \
    -static \
    -O2 \
    -Wfatal-errors -w \
    ${problem} \
    -o a.out
TEST_FILE = test.txt
RESULT_FILE = result.txt

solution: 
	$(CPP) $(ARGS_CODEFORCES) 
	./a.out < $(TEST_FILE) > $(RESULT_FILE)
	cat $(RESULT_FILE)

endif