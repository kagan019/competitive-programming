ifdef problem

CPP = g++
ARGS_KATTIS = -g -ggdb -Wfatal-errors -w -std=gnu++17 \
	${problem} -o a.out -fsanitize=address
TEST_FILE = test.txt
RESULT_FILE = result.txt

solution:
	$(CPP) $(ARGS_KATTIS) 
	./a.out < $(TEST_FILE) > $(RESULT_FILE)
	cat $(RESULT_FILE)
endif