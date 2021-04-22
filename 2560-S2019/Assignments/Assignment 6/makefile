CC=gcc
CFLAGS=-Wall -O2

all: q1 q2
q1: client server
q2: rock doozer

server: server.o
	$(CC) -o $@ $^

client: client.o
	$(CC) -o $@ $^

rock: rock.o
	$(CC) -o $@ $^ -pthread

doozer: doozer.o
	$(CC) -o $@ $^ -pthread

server.o: server.c msg.h
	$(CC) $(CFLAGS) -c $<

client.o: client.c msg.h
	$(CC) $(CFLAGS) -c $<

rock.o: rock.c
	$(CC) $(CFLAGS) -c $<

doozer.o: doozer.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f core *.o server client rock doozer

