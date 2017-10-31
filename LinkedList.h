//Known problems: function at returns void if the index is invalid and not out 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedListInterface.h"
#include <sstream> 
#include <stdexcept>

using namespace std;

template <class ItemType>
class LinkedList: public LinkedListInterface <ItemType> {
	private:
		Node<ItemType> *head=NULL;
		Node<ItemType> *tail=NULL;
		int actualSize;
	public:
	~LinkedList(){
		clear();
	}
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
	 	
	 	if(head==NULL){
	 		insertHead(value);
	 		//actualSize++; done in insert head
	 		return;
	 	}
	 	cout<<"insertTail "<<value<<endl;
	 	if(actualSize ==1){	//head and tail are the same value
	 		head ->next = new Node<ItemType>(value);
	 		tail = head->next;
	 		actualSize++;
	 		return;
	 	}
	 	Node<ItemType> *temp = new Node<ItemType>(value);
	 	tail->next =temp;
	 	tail=temp;
	 	actualSize++;
		cout<<toString()<<endl;
	 }

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
	 	cout<<toString()<<endl;
	 	updateTail();
	 }
	 void updateTail(){
	 	if(actualSize==0){
	 		tail=NULL;
	 		return;
	 	}
	 	Node<ItemType> *curr = head;
	 	while(curr->next != NULL){
	 		//cout<<"1\n";
	 		curr = curr->next;	
	 	}
	 	//cout<<"2\n";
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
	 	cout<<"removing: "<<value<<endl;
	 	cout<<toString()<<endl;
	 	Node<ItemType> *curr = head;
	 	Node<ItemType> *previous=head;
	 	while(curr != NULL){
	 		cout<<curr->data<<endl;
	 		if(curr->data == value){	//I found you
				previous->next=curr->next;
				if(curr==head){//edge case
					head=curr->next;
				}
				delete curr;
				actualSize--;
				updateTail();
				//cout<<toString()<<endl;
				return;
	 		}
	 		previous=curr;
	 		curr = curr->next;
	 	}
	 	//cout<<"\n\n\n\n\nsomething went terribly wrong";
	 }

	/*
	clear

	Remove all Node<ItemType>s from the list.
	*/
	 void clear(){
	 	cout<<toString()<<endl;
	 	while(actualSize >0){
	 		Node<ItemType> *curr = head;
	 		Node<ItemType> *previous = head;
	 		while(curr->next != NULL){
	 			previous=curr;
	 			curr = curr->next;
	 		}
	 		previous->next = NULL;
	 		cout<<"deleting "<<curr->data<<endl;
	 		delete curr;
	 		actualSize--;
	 	}
	 	head=NULL;
	 	tail=NULL;
	 
	 }
	 ItemType at(int index){
	 	if(index >= size()||index<0)
	 		throw std::out_of_range("out_of_range");
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
	 	string ans = ss.str();
	 	return ans.substr(0,ans.size()-1);
	 }
};
#endif
