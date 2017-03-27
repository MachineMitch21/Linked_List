
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../Header/list.h"

int main(int argc, char* argv[]){
	list<int> my_list;
	my_list.push_node(1);
	my_list.push_node(4);
	my_list.insert(0, 23);
	my_list.remove(0);

	printf("my_list is %d elements long.\n", my_list.length());
	return 0;
}
