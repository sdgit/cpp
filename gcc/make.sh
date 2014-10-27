echo "Making Executable"
g++ -c -g -I ../src/ ../src/binary_tree.cpp && \
g++ -c -g -I ../src/ ../src/Socket.cpp && \
g++ -c -g -I ../src/ ../src/linkedlist.cpp
g++ -c -g -I ../src/ ../src/map.cpp
g++ -c -g -I ../src/ ../src/misc.cpp
g++ -c -g -I ../src/ ../src/my_class.cpp
g++ -c -g -I ../src/ ../src/number_utils.cpp
g++ -c -g -I ../src/ ../src/sort.cpp
g++ -c -g -I ../src/ ../src/stack.cpp
g++ -c -g -I ../src/ ../src/stringfunctions.cpp
g++ -c -g -I ../src/ ../src/test.cpp
g++ -c -g -I ../src/ ../src/trie.cpp
g++ -c -g -I ../src/ ../src/Thread.cpp
g++ -g Socket.o binary_tree.o linkedlist.o map.o misc.o my_class.o number_utils.o sort.o stack.o stringfunctions.o test.o trie.o Thread.o -o interview -lpthread
