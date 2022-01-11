/*
	An example:
		//test.cpp
		#include <bits/stdc++.h>
		using namespace std;
		ostream& double_link_data_output(ostream& os,int data)
		{
			return os<<data;
		}
		#include "double_link.h"
		int main()
		{
			double_link<int> a;
			a.Clear();
			a.push_back(1);
			a.show_list(cout);
			cout<<endl;
			a.push_back(2);
			a.show_list(cout);
			cout<<endl;
			a.push_back(3);
			a.show_list(cout);
			cout<<endl;
			return 0;
		}
	
	Output:
		1
		12
		123
*/
#ifndef HLS_DOUBLE_LINK_H
#define HLS_DOUBLE_LINK_H

#include "common/fstream.h"

template <class T>
class double_link;

template <class T>
class double_link_node
{
	public:
		double_link_node()
		{
			pre=NULL;
			next=NULL;
			return;
		}
		double_link_node(T data)
		{
			this->data=data;
			pre=NULL;
			next=NULL;
			return;
		}
		void set_data(T data)
		{
			this->data=data;
			return;
		}
		T get_data()
		{
			return this->data;
		}
		friend class double_link<T>;
		
		friend ostream& operator<<(ostream& os,double_link_node<T>* node)
		{
			return double_link_data_output(os,node->data);
			//If compile error, please state an output fuction before include double_link.h
			//For example, see the beginning of the file.
			//
			//function example:
			//ostream& double_link_data_output(ostream& os,int data)
			//{
			//	return os<<data;
			//}
			//
		}
		
//		double_link_node<T>& operator++()//p++
//		{
//			double_link_node<T>*p=this;
//			(*this)=*(this->next);
//			return *p;
//		}
//		
//		double_link_node<T>& operator++(T)//++p
//		{
//			(*this)=*(this->next);
//			return *this;
//		}
//		
//		double_link_node<T>& operator--()//p--
//		{
//			double_link_node<T>*p=this;
//			(*this)=*(this->pre);
//			return *p;
//		}
//		
//		double_link_node<T>& operator--(T)//--p
//		{
//			(*this)=*(this->pre);
//			return *this;
//		}
//		
//	private:
		T data;
		double_link_node<T> *next;
		double_link_node<T>	*pre;
};

template <class T>
class double_link
{
	public:
		T error;
		
		double_link()
		{
			first=last=new double_link_node<T>;
			size=0;
			return;
		}
		
		bool is_empyt()
		{
			if(size==0)
				return true;
			return false;
		}
		
		void Clear()
		{
			if(is_empyt())
				return;
			double_link_node<T>* p=first->next;
			double_link_node<T>* temp=NULL;
			while(p!=last)
			{
				temp=p;
				delete temp;
				p=p->next;
			}
			last=first;
			size=0;
			return;
		}
		
		unsigned int length()
		{
			return size;
		}
		
		void show_list(ostream& out)
		{
			if(is_empyt())
				return;
			double_link_node<T>* p=first->next;
			while(p!=NULL)
			{
				out<<p;
				p=p->next;
			}
			return;
		}
		
		double_link_node<T>* get_node(int index)
		{
			if(is_empyt())
				return NULL;
			if(index<0 || index>size)
				return NULL;
			double_link_node<T>* p=first->next;
			for(int i=0;i<size;i++)
			{
				if(i==index)
					break;
				p=p->next;
			}
			return p;
		}
		
		void insert_index(T data,int index)
		{
			if(index<0 || index>size)
				return;
			double_link_node<T>* node=new double_link_node<T>(data);
			if(size==0)
			{
				node->pre=first;
				first->next=node;
				last=node;
			}
			else if(index==0)
			{
				node->pre=first;
				node->next=first->next;
				first->next->pre=node;
				first->next=node;
			}
			else if(index==size)
			{
				last->next=node;
				node->pre=last;
				last=node;
			}
			else
			{
				double_link_node<T>* pre_node=get_node(index-1);
				node->pre=pre_node;
				node->next=pre_node->next;
				pre_node->next->pre=node;
				pre_node->next=node;
			}
			size++;
			return;
		}
		
		void push_back(T data)
		{
			insert_index(data,size);
			return;
		}
		
		void push_front(T data)
		{
			insert_index(data,0);
			return;
		}
		
		T pop_index(int index)
		{
			if(index<0 || index>size-1)
				return error;		
			double_link_node<T>* node=NULL;
			if(index==0)
			{
				node=first->next;
				first->next=node->next;
				node->pre=first;
				if(size==1)
					last=first;
			}
			else if(index==size-1)
			{
				node=last;
				last=last->pre;
				last->next=NULL;
			}
			else
			{
				node=get_node(index);
				node->pre->next=node->next;
				node->next->pre=node->pre;
			}
			T data=node->data;
			delete node;
			size--;
			return data;
		}
		
		T pop_back()
		{
			return pop_index(size-1);
		}
		
		T pop_front()
		{
			return pop_index(0);
		}
		
		T operator[](int index)
		{
			return get_node(index)->get_data();
		}
		
	private:
		double_link_node<T>* first;
		double_link_node<T>* last;
		int size;
};

#endif
//https://blog.csdn.net/cj_bigniu/article/details/109901651
