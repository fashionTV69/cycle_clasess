#include <iostream>
struct buffer_node {
	int num;
	buffer_node* right;
};
class Cycle_buffer {
private:
	buffer_node* begin;
	buffer_node* end;
public:
	void init();
	void add_num(int num_to_add);
	bool del_num(int num_to_del);
	bool find_num(int num_to_find);
};