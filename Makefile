main:	configparse.l configparse.y configparse.h main.c
		bison -d configparse.y
		flex -o configparse.lex.c configparse.l
		cc -gdwarf-2 -o $@ configparse.tab.c configparse.lex.c main.c
