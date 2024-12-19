clean:
	rm $(wildcard *.o) $(wildcard *.exe)
	@echo "removed .o and .exe files"

linked-list: main.c void-pointer/void_pointer.c linked-list/linked_list.c
	gcc $^ -o $@
	@echo "$^ compiled into $@" 

binary-tree: main.c void-pointer/void_pointer.c binary-tree/binary_tree.c
	gcc $^ -o $@
	@echo "$^ compiled into $@"

vector: main.c vector/vector.c
	gcc $^ -o $@
	@echo "$^ compiled into $@"
