// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "cycle_vector.h"
void Cycle_buffer::init() {
}
void Cycle_buffer::add_num(int num_to_add) {
	if (buffer.empty()|| buffer[buffer.size()-1]<= num_to_add)//empty buffer
	{
		buffer.push_back(num_to_add);
	}
	else {
		if (buffer[0]< num_to_add) {
			buffer.insert(buffer.begin(), num_to_add);
		}
		else {
			int i = 0;
			while (buffer[i] < num_to_add)
			{
				i++;
			}
			buffer.insert(buffer.begin()+i, num_to_add);
		}
	}
}
bool Cycle_buffer::del_num(int num_to_del) {
	int num = this->find_num(num_to_del);
	if (num == -1)
	{
		return false;
	}
	else {
		buffer.erase(buffer.begin()+num);
	}
}
int Cycle_buffer::find_num(int num_to_find) {
	int right = buffer.size()-1;
	int left = 0;
	int mid = 0;
	while (1)
	{
		mid = (left + right) / 2;

		if (num_to_find < buffer[mid])
			right = mid - 1;      
		else if (num_to_find > buffer[mid])
			left = mid + 1;    
		else                     
			return mid;          

		if (left > right)         
			return -1;
	}
}

