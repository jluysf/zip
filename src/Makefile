CC = gcc
DEL = rm -f

TARGET = unzip

All:$(TARGET)

OBJS = unzip.o zip.o

$(TARGET):$(OBJS)
	$(CC) -I. $(OBJS) -o $(TARGET)

clean:
	$(DEL) *.o
	$(DEL) $(TARGET)
