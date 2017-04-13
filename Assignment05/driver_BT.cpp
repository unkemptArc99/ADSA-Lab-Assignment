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
#include "hash_main.hpp"

int main(int argc, char *argv[]){
    std::cout<<"Welcome to the Binary Tree Driver Program"<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
    cs202::BinaryTree<unsigned int,int> A;
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
        unsigned int key_intval;
        std::string key;
        std::cout<<"Enter your choice"<<std::endl;
        std::cin>>ch;
        switch(ch){
            case 1:
                std::cout<<"Enter the key you want to store";
                std::cin>>key;
                key_intval = cs202_hash::primary_hash_map(key);
                std::cout<<"Enter the value you want to store with the above associated key";
                std::cin>>value;
                A.put(key_intval,value);
                break;
            case 2:
                std::cout<<"Enter the key you want to remove";
                std::cin>>key;
                key_intval = cs202_hash::primary_hash_map(key);
                try{
                    A.remove(key_intval);
                }
                catch(int error){
                    if(error == -1){
                        std::cout<<"The inputted key is not stored in the tree";
                        break;
                    }
                }
                std::cout<<"Element deleted"<<std::endl;
                break;
            case 3:
                std::cout<<"Enter the key for which you want to access the value : ";
                std::cin>>key;
                key_intval = cs202_hash::primary_hash_map(key);
                try{
                    value = A.get(key_intval);
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
                key_intval = cs202_hash::primary_hash_map(key);
                if(A.has(key_intval))
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
        }
    }
    return 0;
}