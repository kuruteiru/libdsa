clean:
	rm $(wildcard *.o) $(wildcard *.exe)
	@echo "removed .o and .exe files"

linked-list: main.c linked-list/linked_list.c
	gcc $^ -o $@
	@echo "$^ compiled into $@" 

binary-tree: main.c binary-tree/binary_tree.c
	gcc $^ -o $@
	@echo "$^ compiled into $@"