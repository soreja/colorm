all: test

%.o: %.cpp
	g++ -Wall -D BOOST_TEST_DYN_LINK -o $@ -c $<

objects = pch.o test_module.o accessor.o blending.o color_strings.o colorscale.o conversion.o manipulation.o operator.o

test: pch.h $(objects)
	g++ -Wall -o test $(objects) -l boost_unit_test_framework

.PHONY: clean
clean:
	rm test $(objects)

