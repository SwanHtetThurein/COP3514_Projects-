project10_guests: guest.o read_line.o project10_guests.o
	gcc -o project10_guests guest.c read_line.c project10_guests.c
project10_guests.o: project10_guests.c
	gcc -c project10_guests.c
guest.o: guest.c guest.h
	gcc -c guest.c
read_line.o: read_line.c read_line.h
	gcc -c read_line.c