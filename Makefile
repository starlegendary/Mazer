main: main.cpp fighting.o command.o default_value.o datas.h
  g++ main.cpp fighting.o command.o default_value.o datas.h -o main
  
fight.o: fighting.cpp
  g++ fighting.cpp -c fighting.o

command.o: command.cpp
  g++ command.cpp -c command.o
  
default_value.o: default_value.cpp
  g++ default_value.cpp -c default_value.o
  
clear:
  rm *.o main
