TARGET = calculadora
OBJS = calculadora.o funciones.o lista.o
CFLAGS = -Wall 

$(TARGET) : $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)
##########################################
%.o : %.c
	gcc -c $(CFLAGS) $< -o $@
##########################################

.PHONY : clean
clean:
	rm -f *.o $(TARGET)



