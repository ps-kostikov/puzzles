CPP_PROBLEMS = \
	1 2 3 4 5 6 7 8 9 10 \
	11 12 13 14 15 17 18 19 \
	21 23 24 26 27 28 \
	31 32 33 34 35 36 37 38 39 40 \
	41 42 43 44 45 46 47 48 49 50 \
	51 52 53 58 60 \
	61 63 67 68 69 70 \
	71 72 73 \
	94 \
	123 \
	151 \

PY_PROBLEMS = \
	16 20 \
	22 25 29 30 \
	55 56 57 59 \
	62 65 \


$(CPP_PROBLEMS): %: common.h common.cpp %.cpp
	g++-4.8 -std=c++11 -O2 common.cpp $@.cpp -o $@

TEST_CPP_PROBLEMS = $(addprefix test-,$(CPP_PROBLEMS))

$(TEST_CPP_PROBLEMS): test-%: %
	./test.sh $* cpp


TEST_PY_PROBLEMS = $(addprefix test-,$(PY_PROBLEMS))

$(TEST_PY_PROBLEMS): test-%:
	./test.sh $* py


all: $(CPP_PROBLEMS)

test: $(TEST_CPP_PROBLEMS) $(TEST_PY_PROBLEMS)
	@echo OK

clean:
	rm -f $(CPP_PROBLEMS)
