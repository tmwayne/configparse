calc:	configparse.l configparse.y configparse.h
		bison -d configparse.y
		flex -o configparse.lex.c configparse.l
		cc -o $@ configparse.tab.c configparse.lex.c configparse.c
