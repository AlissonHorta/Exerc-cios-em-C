TARGET = ProvaTrimestral

all:
	make compilar
	make run
	make clean

compilar: main.c sacola.c sacola.h
	gcc -o $(TARGET) main.c sacola.c sacola.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)