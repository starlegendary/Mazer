FLAGS = -pedantic-errors -std=c++11

movement.o: movement.cpp datas.h
  g++ $(FLAGS) movement.cpp -c movement.o
  
display.o: display.cpp datas.h
  g++ $(FLAGS) display.cpp -c display.o
  
fighting.o: fighting.cpp datas.h
  g++ $(FLAGS) fighting.cpp -c fighting.o

command.o: command.cpp datas.h
  g++ $(FLAGS) command.cpp -c command.o
  
default_value.o: default_value.cpp datas.h 
  g++ $(FLAGS) default_value.cpp -c default_value.o
  
main: main.cpp fighting.o command.o default_value.o movement.o display.o datas.h
  g++ $(FLAGS) main.cpp fighting.o command.o default_value.o movement.o display.o-o main
  
clean:
  rm *.o main
