# NOTE: flag setting currently needed on laptop for latest C++ standard
# but on Lab machines the install of g++ effectively entails this setting
# CPPFLAGS = -std=c++14 -g
CPPFLAGS = -g
FSA.o: FSA.cpp FSA.h Node.h
	g++ $(CPPFLAGS) -c FSA.cpp

FSA_partial.o: FSA_partial.cpp FSA.h Node.h
	g++ $(CPPFLAGS) -c FSA_partial.cpp

Node.o: Node.cpp Node.h
	g++ $(CPPFLAGS) -c Node.cpp

Node_partial.o: Node_partial.cpp Node.h
	g++ $(CPPFLAGS) -c Node_partial.cpp

tester_pictures.o: tester_pictures.cpp FSA.h Node.h
	g++ $(CPPFLAGS) -c tester_pictures.cpp

tester_pictures: FSA.o Node.o tester_pictures.o
	g++ $(CPPFLAGS) FSA.o Node.o tester_pictures.o -o tester_pictures

tester.o: tester.cpp FSA.h Node.h
	g++ $(CPPFLAGS) -c tester.cpp

# tester: FSA_partial.o Node.o tester.o
# 	g++ $(CPPFLAGS) FSA_partial.o Node.o tester.o -o tester

tester: FSA.o Node.o tester.o
	g++ $(CPPFLAGS) FSA.o Node.o tester.o -o tester

clean:
	rm FSA.o Node.o tester_pictures.o tester.o
