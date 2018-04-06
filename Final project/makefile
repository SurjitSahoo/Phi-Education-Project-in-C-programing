default: final_project

CFLAGS = -g -Wall -Wextra

obj = convert.o read_data.o sortlist.o sorted_insert.o loadData.o

final_project: main.c $(obj) libstr.a dictionary.a
	gcc $(CFLAGS) $^ -o $@

$(obj): convert.c read_data.c sortlist.c sorted_insert.c loadData.c
	gcc $(CFLAGS) -c $^
