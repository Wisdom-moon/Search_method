search: main.c fitness.c util.c hill.c anneal.c
	gcc -O0 -g3 -ggdb -lrt -lm -o $@ $^

clean:
	rm search
