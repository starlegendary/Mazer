FLAGS = -pedantic-errors -std=c++11

movement.o: movement.cpp datas.h
        g++ $(FLAGS) -c $<
  
display.o: display.cpp datas.h
        g++ $(FLAGS) -c $<
  
fighting.o: fighting.cpp datas.h
        g++ $(FLAGS) -c $<

command.o: command.cpp datas.h
        g++ $(FLAGS) -c $<
  
default_value.o: default_value.cpp datas.h 
        g++ $(FLAGS) -c $<
  
main: main.cpp fighting.o command.o default_value.o movement.o display.o datas.h
        g++ $(FLAGS) $^ -o $@
  
clean:
        rm *.o main
  
  
