// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "dynamic cycle byffer.h"
void Cycle_buffer::init() {
	begin = NULL;
	end = NULL;
}
void Cycle_buffer::add_num(int num_to_add) {
	if (begin == NULL)//empty buffer
	{
		begin = new struct buffer_node;
		begin->num = num_to_add;
		begin->right = begin;
		end = begin;
	}
	else {
		if (begin->num >= num_to_add) {
			struct buffer_node* temp= new struct buffer_node;
			temp->right = begin;
			temp->num = num_to_add;
			end->right = temp;
			begin = temp;
		}
		else if (begin->num >= num_to_add) {
			struct buffer_node* temp = new struct buffer_node;
			temp->right = begin;
			temp->num = num_to_add;
			end->right = temp;
			end = temp;
		}
		else {
			struct buffer_node* slider = begin;
			while (slider->right->num < num_to_add) {
				slider = slider->right;
			}
			struct buffer_node* temp = new struct buffer_node;
			temp->right = slider->right;
			temp->num = num_to_add;
			slider->right = temp;
		}
	}
}
bool Cycle_buffer::del_num(int num_to_del) {
	if (begin == NULL)//empty buffer
	{
		return false;
	}
	else {
		struct buffer_node* slider = begin;
		if (slider->num == num_to_del)
		{
			end = begin->right;
			delete slider;
			return true;
		}
		while (slider->right->num != num_to_del && slider->right != begin) {
			slider = slider->right;
		}
		if (slider->right == begin)
		{
			return true;
		}
		slider->right = slider->right->right;
		delete slider->right;
		return true;
	}
}
bool Cycle_buffer::find_num(int num_to_find) {
	if (begin == NULL)//empty buffer
	{
		return false;
	}
	else {
		struct buffer_node* slider = begin;
		if (slider->num == num_to_find)
		{
			end = begin->right;
			return true;
		}
		while (slider->right->num != num_to_find && slider->right != begin) {
			slider = slider->right;
		}
		if (slider->right == begin)
		{
			return true;
		}
		slider->right = slider->right->right;
		return true;
	}
}

