#include <iostream>

class Node{
public:
	int data;
	Node* next;

	Node(int da = 0, Node *p = NULL){
		this->data = da;
		this->next = p;
	}
};

class List{
private:
	Node *head, *tail;
	int position;
public:
	List() { head = tail = NULL };
	
	~List(){
		delete head;
		delete tail;
	}

	void print();
	void Insert();
	void Delete();
	void Search();
	int getValueAt(int position);
	void setValueAt(int poistion, int da);
};

int List::getValueAt(int position){
	Node *p = head;
	if(p == NULL){
		std::cout << " The list is empty! " << std::endl;
	}else{
		int posi = 0;
		while(p != NULL && posi != position){
			posi++;
			p = p->next;
		}
		if(p == NULL){
			std::cout << "There is no value of this poistion in this List!" << std::endl;
		}else{
			std::cout << "In this position, the value is: " << p->data << std::endl;
		}
	}
	return p->data;
}

void List::setValueAt(int position, int da){
	Node *p = head;
	if(p == NULL){
		std::cout << " The list is empty! " << std::endl; 
	}else{
		int posi = 0;
		while(p != NULL && posi != position){
			posi++;
			p = p->next;
		}
		if(p == NULL){
			std::cout << "There is no position in this list!" << std::endl;
		}else{
			p->data = da;
			std::cout << "The value in this position has been updated! " << std::endl;
		}
	}
}

void List::Search(int da){
	Node *p = head;
	if(p == NULL){
		std::cout << "Sorry, The List is empty!" << std::endl;
		return; 
	}
	int count = 0;
	while(p != NULL && p->data != da){
		p = p->next;
		count++;
	}
	std::cout << "The value you want to search is at position: " << count << std::endl;
}

void List::Delete(int da){
	Node *p = head, *q = head;
	if(p == NULL){
		std::cout << "Sorry, The List is empty! " << std::endl;
		return;
	}
	while(p != NULL && p->data != da){
		q = p;
		p = p->next;
	}
	q->next = p->next;
	std::cout << "The deletion operation had been finished! " << std::endl;
}

void List::Insert(int da){
	if(head == NULL){
		head = tail = new Node(da);
		head->next = NULL;
		tail->next = NULL:
	}else{
		Node *p = new Node(da);
		tail->next = p;
		tail = p;
		tail->next = NULL:
	}
}

void List::print(){
	Node *p = head;
	while(p != NULL){
		std::cout << p->data << " \a";
		p = p->next;
	}
	std::cout << std::endl;
}






