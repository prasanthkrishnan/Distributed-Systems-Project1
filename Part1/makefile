UnOpt: P1-Part1-lib.c P1-Part1-client.c P1-Part1-server.c
	gcc -lrt -o client.out P1-Part1-lib.c P1-Part1-client.c -I.
	gcc -o server.out P1-Part1-lib.c P1-Part1-server.c -I.
Opt: P1-Part1-lib.c P1-Part1-client.c P1-Part1-server.c
	gcc -O -lrt -o client.out P1-Part1-lib.c P1-Part1-client.c -I.
	gcc -O -o server.out P1-Part1-lib.c P1-Part1-server.c -I.
clean: client.out server.out
	rm client.out server.out