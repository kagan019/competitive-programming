ifdef problem

CPP = g++
ARGS_CODEFORCES = \
	-g \
    -ggdb \
    -static \
    "${problem}" \
    -o a.exe
TEST_FILE = test.txt
RESULT_FILE = result.txt

solution: 
	$(CPP) $(ARGS_CODEFORCES) 
	a.exe < $(TEST_FILE) > $(RESULT_FILE)
	type result.txt

interactive:
	$(CPP) $(ARGS_CODEFORCES)
	python2.7 interactive_runner.py python testing_tool.py 0 -- ./a.exe

endif