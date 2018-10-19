#include "node.h"
#include <iostream>

template <typename T>
Node<T>::Node()
{
    this->m_data = NULL; //Fjerner garbage value under første
    this->m_father = nullptr; //setter alle til nullpointers
    this->m_hsub = nullptr;
    this->m_vsub = nullptr;
}

template <typename T>
Node<T>::Node(int m_data){
    this->m_data = m_data;
    this->m_father = nullptr;
    this->m_hsub = nullptr;
    this->m_vsub = nullptr;

}

template <typename T>
int Node<T>::GetValue(){
    return m_data;
}

template <typename T>
void Node<T>::SetValue(int m_data){
    this->m_data = m_data;
}

template <typename T>
Node<T>* Node<T>::insert(Node<T>* root, T m_data){
    if(root->GetValue() == NULL){
        root->SetValue(m_data);
        root->m_father = nullptr;
    }
    else{
        if(m_data > root->GetValue()){
            if(root->m_hsub){
                insert(root->m_hsub, m_data);
            }
            else
                root->m_hsub = new Node<T>(m_data);
                root->m_hsub->m_father = root;
        }
        else if(m_data < root->GetValue()){
            if(root->m_vsub){
                insert(root->m_vsub, m_data);
            }
            else
                root->m_vsub = new Node<T>(m_data);
                root->m_vsub->m_father = root;
            }
    }
    return root;
}

template <typename T>
void Node<T>::preOrder(Node<T>* root){ //Før jeg sorterer
    if(root!=nullptr){
        std::cout << root->GetValue() << " ";
        preOrder(root->m_vsub);
        preOrder(root->m_hsub);
    }
}


template <typename T>
void Node<T>::postOrder(Node<T>* root){ // etter sortering
    if(root!=nullptr){

        postOrder(root->m_vsub);
        postOrder(root->m_hsub);
        std::cout << root->GetValue() << " ";
    }
}


//sletter
template <typename T>
void Node<T>::Delete(Node<T>* root, int Data){
    if( root!= nullptr && root->GetValue() != Data ){ // hvis noden som sendes inn ikke er en nullptr og den ikke er samme som int-en som sendes inn, gå videre inn i treet
        if(root->GetValue() > Data){
            Delete(root->m_vsub, Data);
        }
        else if(root->GetValue() < Data){
            Delete(root->m_hsub, Data);
        }
    }
    else{ //Hvis den ikke har en høyre eller venstre subtre
        if(!root->m_vsub && !root->m_hsub){
            Node<T>* temp = root->m_father;
            if(temp->m_vsub == root){
                temp->m_vsub = nullptr;
                delete root;
            }
            else if(temp->m_hsub == root){
                temp->m_hsub = nullptr;
                delete root;
            }
        }
        // hvis den ikke har en venstre subtree
        else if(!root->m_vsub){
           Node<T>* temp = root;
           root = temp->m_hsub;
           root->m_father = temp->m_father;

           if(root->m_father->m_hsub == temp){
               root->m_father->m_hsub = root;
           }
           else{
               root->m_father->m_vsub = root;
           }
           delete temp;
}
        //Hvis den har en venstre subtree
        else if(root->m_vsub){
           Node<T>* temp = root;
           root = temp->m_vsub;
           root->m_father = temp->m_father;

           if(root->m_father->m_vsub == temp){
               root->m_father->m_vsub = root;
           }
           else{
               root->m_father->m_hsub = root;
           }
           delete temp;
}
    }
}
