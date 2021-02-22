ifdef problem

CPP = g++
ARGS_CODEFORCES = \
	-g \
    -ggdb \
    -static \
    "${problem}" \
    -o a.out
TEST_FILE = test.txt
RESULT_FILE = result.txt

solution: 
	$(CPP) $(ARGS_CODEFORCES) 
	./a.out < $(TEST_FILE) > $(RESULT_FILE)
	cat result.txt

interactive:
	$(CPP) $(ARGS_CODEFORCES)
	python2.7 interactive_runner.py python testing_tool.py 0 -- ./a.exe

endif