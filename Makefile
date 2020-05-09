movement.o: movement.cpp datas.h
  g++ movement.cpp -c movement.o
  
display.o: display.cpp datas.h
  g++ display.cpp -c display.o
  
fight.o: fighting.cpp datas.h
  g++ fighting.cpp -c fighting.o

command.o: command.cpp datas.h
  g++ command.cpp -c command.o
  
default_value.o: default_value.cpp datas.h 
  g++ default_value.cpp -c default_value.o
  
main: main.cpp fighting.o command.o default_value.o movement.o display.o datas.h
  g++ main.cpp fighting.o command.o default_value.o movement.o display.o-o main
  
clean:
  rm *.o main
