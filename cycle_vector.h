#include <iostream>
#include <vector>
class Cycle_buffer {
private:
	std::vector <int> buffer;
public:
	void init();
	void add_num(int num_to_add);
	bool del_num(int num_to_del);
	int find_num(int num_to_find);
};