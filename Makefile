win:
	gcc main.c s21_*.c -o test1
	./test1.exe

mac:
	gcc main.c s21_*.c -o test1
	./test1

testya:
	gcc s21_*.c ./tests/unit_tests.c -o my_test
	./tests/my_test