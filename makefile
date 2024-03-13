clean:
	rm $(wildcard *.o) $(wildcard *.exe)
	@echo "removed .o and .exe files"

linkedList: linked-list/linkedList.c
	gcc $^ -o $@
	@echo "$^ compiled into $@" 