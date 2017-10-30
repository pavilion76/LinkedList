//Known problems: function at returns void if the index is invalid

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedListInterface.h"
#include <sstream> 

using namespace std;

template <class ItemType>
class LinkedList: public LinkedListInterface <ItemType> {
	private:
		Node<ItemType> *head=NULL;
		Node<ItemType> *tail=NULL;
		int actualSize;
	public:
		/*
	insertHead

	A Node<ItemType> with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(ItemType value){
		if(thereIsADuplicate(value)){
			return;
		}
		cout<<"insertHead "<<value<<endl;
		if(actualSize <1){
			head = new Node<ItemType>(value);
			tail=head;
			actualSize++;
			return;
		}
		Node<ItemType> *temp=new Node<ItemType>(value);
		temp->next = head;
		head = temp;
		actualSize++;
	}
	void insertTail(ItemType value){
		if(thereIsADuplicate(value)){
			return;
		}
	 	cout<<"insertTail "<<value<<endl;
	 	if(head==NULL){
	 		insertHead(value);
	 		//actualSize++; done in insert head
	 		return;
	 	}
	 	if(actualSize ==1){
	 		head ->next = new Node<ItemType>(value);
	 		tail = head->next;
	 		actualSize++;
	 		return;
	 	}
	 	Node<ItemType> *temp = new Node<ItemType>(value);
	 	tail->next =temp;
	 	tail=temp;
	 	actualSize++;
		cout<<"new tail "<<tail->data<<endl;
	 }

	/*
	insertAfter

	A Node<ItemType> with the given value should be inserted immediately after the
	Node<ItemType> whose value is equal to insertionNode.

	A Node<ItemType> should only be added if the Node<ItemType> whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	 void insertAfter(ItemType value, ItemType insertionNode){
	 	cout<<toString();
	 	cout<<"insertAfter "<<insertionNode<<endl;
	 	Node<ItemType> *curr = head;
	 	Node<ItemType> *here = NULL;
	 	while(curr != NULL){	//I have to go through the entire array to see if there will be a duplicate
	 		if(curr->data == value){	//if there is a duplicate
				//I do not need to delete because I still want the data
				return;		 		
	 		}
	 		if(curr->data == insertionNode){	//found where the new Node<ItemType> goes
	 			cout<<"2\n";
	 			here=curr;
	 		}
	 		//cout<<"next val "<<curr->next<<endl;
	 		curr = curr->next;	
	 	}
	 	if(here == NULL)
	 		return;
	 	Node<ItemType> *temp = new Node<ItemType>(value);
	 	temp->next = here->next;
	 	here->next = temp;
	 	actualSize++;
	 	cout<<toString();
	 	updateTail();
	 }
	 void updateTail(){
	 	Node<ItemType> *curr = head;
	 	while(curr->next != NULL){
	 		curr = curr->next;	
	 	}
	 	tail=curr;
	 }
	 //returns true if a duplicate is found, returns false otherwise.
	 bool thereIsADuplicate(ItemType value){
	 	Node<ItemType> *curr = head;
	 	while(curr != NULL){
	 		if(curr->data == value){	//if there is a duplicate
				return true;		 		
	 		}
	 		curr = curr->next;
	 	}
	 	return false;
	 }

	/*
	remove

	The Node<ItemType> with the given value should be removed from the list.

	The list may or may not include a Node<ItemType> with the given value.
	*/
	 void remove(ItemType value){
	 	Node<ItemType> *curr = head;
	 	Node<ItemType> *previous;
	 	while(curr != NULL){
	 		if(curr->data == value){	//I found you
				previous->next=curr->next;
				delete curr;
				actualSize--;
				return;
	 		}
	 		previous=curr;
	 		curr = curr->next;
	 	}
	 }

	/*
	clear

	Remove all Node<ItemType>s from the list.
	*/
	 void clear(){
	 	while(actualSize >0){
	 		Node<ItemType> *curr = head;
	 		while(curr != NULL)
	 			curr = curr->next;
	 		delete curr;
	 		actualSize--;
	 	}
	 	head=NULL;
	 	tail=NULL;
	 
	 }

	/*
	at

	Returns the value of the Node<ItemType> at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	 ItemType at(int index){
	 	cout<<"index: "<<index<<" size "<<size()<<endl;
	 	if(index >= size()||index<0){
	 		cout<<"error 404\n";
	 		Node<ItemType> temp;
	 		return temp.data;
	 	}
	 	Node<ItemType> *curr = head;
	 	for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
	 }
	 
	 
	 int size(){
	 	return actualSize;
	 }
	 string toString(){
	 	string outPut="";
	 	Node<ItemType> *curr = head;
	 	stringstream ss;
	 	while(curr != NULL){
	 		ss<<curr->data<<" ";
	 		curr = curr->next;	
	 	}
	 	return ss.str();
	 }
};
#endif
