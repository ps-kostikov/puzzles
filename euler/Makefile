PROBLEMS=1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 18 151

$(PROBLEMS): common.h common.cpp
	g++-4.8 -std=c++11 -O2 common.cpp $@.cpp -o $@

# test:
# 	[[ `./1` = "233168" ]] && echo 1 OK || echo 1 FAIL

clean:
	rm -f $(PROBLEMS)
