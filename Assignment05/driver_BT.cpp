/******************************************************************************
Author : Abhishek
Roll No. : B15103
CS202 - ADSA - Assignment05 - Binary Tree driver file
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include "BinaryTree.hpp"

int main(int argc, char *argv[]){
    std::cout<<"Welcome to the Binary Tree Driver Program"<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
    cs202::BinaryTree<std::string,int> A;
    int length = 0;
    while(1){
        std::cout<<"1. Insert into the Tree"<<std::endl;
        std::cout<<"2. Remove a key from the Tree"<<std::endl;
        std::cout<<"3. Get a value corresponding to a key in the editor"<<std::endl;
        std::cout<<"4. Check if a key exists or not"<<std::endl;
        std::cout<<"5. Print inorder"<<std::endl;
        std::cout<<"6. Print preorder"<<std::endl;
        std::cout<<"7. Print postorder"<<std::endl;
        std::cout<<"8. Print the minimum key"<<std::endl;
        std::cout<<"9. Print the maximum key"<<std::endl;
        std::cout<<"10. Find the successor of a key"<<std::endl;
        std::cout<<"11. Find the predecessor of a key"<<std::endl;
        std::cout<<"12. Exit"<<std::endl;
        int ch,value;
        std::string key,key1;
        std::cout<<"Enter your choice"<<std::endl;
        std::cin>>ch;
        switch(ch){
            case 1:
                std::cout<<"Enter the key you want to store : ";
                std::cin>>key;
                std::cout<<"Enter the value you want to store with the above associated key : ";
                std::cin>>value;
                A.put(key,value);
                length++;
                break;
            case 2:
                std::cout<<"Enter the key you want to remove : ";
                std::cin>>key;
                if(length > 0){
                    try{
                        A.remove(key);
                    }
                    catch(int error){
                        if(error == -1){
                            std::cout<<"The inputted key is not stored in the tree"<<std::endl;
                            break;
                        }
                    }
                    std::cout<<"Element deleted"<<std::endl;
                    length--;
                }
                else{
                    std::cout<<"Not enough elements to remove"<<std::endl;
                }
                break;
            case 3:
                std::cout<<"Enter the key for which you want to access the value : ";
                std::cin>>key;
                try{
                    value = A.get(key);
                }
                catch(int error){
                    if(error == -1){
                        std::cout<<"The provided key has no corresponding value stored."<<std::endl;
                        break;
                    }
                }
                std::cout<<"Key : "<<key<<" Value : "<<value<<std::endl;
                break;
            case 4:
                std::cout<<"Enter the key : ";
                std::cin>>key;
                if(A.has(key))
                    std::cout<<"Yes! The key exists!"<<std::endl;
                else
                    std::cout<<"No! The key does not exists!"<<std::endl;
                break;
            case 5:
                A.print_in_order();
                break;
            case 6:
                A.print_pre_order();
                break;
            case 7:
                A.print_post_order();
                break;
            case 8:
                std::cout<<"The minimum key in the tree is "<<A.minimum()<<std::endl;
                break;
            case 9:
                std::cout<<"The maximum key in the tree is "<<A.maximum()<<std::endl;
                break;
            case 10:
                std::cout<<"Enter the key : ";
                std::cin>>key;
                try{
                    key1 = A.successor(key);
                }
                catch(int error){
                    if(error == -2){
                        std::cout<<"The successor is \"NULL\""<<std::endl;
                    }
                    if(error == -1){
                        std::cout<<"The element does not exist"<<std::endl;
                    }
                    break;
                }
                std::cout<<"The successor key is "<<key1<<std::endl;
                break;
            case 11:
                std::cout<<"Enter the key : ";
                std::cin>>key;
                try{
                    key1 = A.predecessor(key);
                }
                catch(int error){
                    if(error == -2){
                        std::cout<<"The predecessor key is \"NULL\""<<std::endl;
                    }
                    if(error == -1){
                        std::cout<<"The element does not exist"<<std::endl;
                    }
                    break;
                }
                std::cout<<"The predecessor key is "<<key1<<std::endl;
                break;
            case 12:
                exit(0);
                break;
            default:
                std::cout<<"Wrong choice! Enter the right one, please!"<<std::endl;
        }
    }
    return 0;
}