COMPILER = g++
main.o  = .\object_files\main.o
hash.o  = .\object_files\hash.o
deque.o = .\object_files\deque.o 
opt     = .\executables\opt.exe



$(main.o) : main.cpp
	$(COMPILER) -c main.cpp -o $(main.o)

$(hash.o) : custom_hashmap.cpp
	$(COMPILER) -c custom_hashmap.cpp -o $(hash.o)

$(deque.o) : custom_deque.cpp
	$(COMPILER) -c custom_deque.cpp -o $(deque.o)

$(opt) : $(main.o) $(hash.o) $(deque.o)
	$(COMPILER) $(main.o) $(hash.o) $(deque.o) -o $(opt) 


run : $(opt)
	$(opt)

clean : $(opt) $(main.o) $(hash.o) $(deque.o)
	@ECHO "Cleaning project!"
	del /Q /F  $(opt) $(main.o) $(hash.o) $(deque.o)
	@ECHO "Clean completed!"

.PHONY : run clean


