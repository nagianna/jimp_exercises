//
// Created by Ania on 2018-06-02.
//


#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>
#include <queue>



namespace tree {

    template <class T>
    class Helper{
    public:
        Helper(){
            index=0;
        }

        ~Helper()=default;

        Helper<T>&operator++() {
            ++index;
            return *this;
        }

        T operator*(){
            return vector[index];
        }

        bool operator!=(const Helper<T> &another)const{
              if(index!=another.index){
                  return true;
              }
            else{
                  return false;
              }
        }

        unsigned long index;
        std::vector<T> vector;
    };

    template<class T>
    class InOrderTreeIterator: public Helper<T>{
    public:
        InOrderTreeIterator()=default;
        explicit InOrderTreeIterator(Tree<T> *new_node){
            InOrderTree(new_node);
        }
        void InOrderTree(Tree<T> *new_);
    };

    template<class T>
    void InOrderTreeIterator<T>::InOrderTree(Tree<T> *new_) {
        if (new_ == nullptr) {
            return;
        }
        else{
            InOrderTree(new_->left_child_.get());
            InOrderTreeIterator::vector.push_back(new_->value_);
            InOrderTree(new_->right_child_.get());
        }
    }
    
    template <class T>
    class InOrderTreeView{
    public:
        InOrderTreeView()=default;
        explicit InOrderTreeView(Tree<T> *tree) : InIterator(tree){};
        ~InOrderTreeView()=default;

        InOrderTreeIterator<T> begin() {
            return InIterator;
        }

        unsigned long EndIndex(InOrderTreeIterator<T> it){
            return it.vector.size()-1;
        }

        InOrderTreeIterator<T> end() {
            InIterator.index=EndIndex(InIterator);
            return InIterator;
        }

    private:
        InOrderTreeIterator<T> InIterator;
    };

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *new_node) {
        return InOrderTreeView<T>(new_node);
    }
    
    

    template<class T>
    class PreOrderTreeIterator: public Helper<T>{
    public:
        PreOrderTreeIterator()=default;
        explicit PreOrderTreeIterator(Tree<T> *new_node){
            PreOrderTree(new_node);
        }
        void PreOrderTree(Tree<T> *new_);
    };
    
    template<class T>
    void PreOrderTreeIterator<T>::PreOrderTree(Tree<T> *new_) {
        if (new_ == nullptr) {
            return;

        }
        else{
            PreOrderTreeIterator::vector.push_back(new_->value_);
            PreOrderTree(new_->left_child_.get());
            PreOrderTree(new_->right_child_.get());
        }
    }


    template <class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView()=default;
        explicit PreOrderTreeView(Tree<T> *tree) : TIterator(tree){};
        ~PreOrderTreeView()=default;
        PreOrderTreeIterator<T> begin() {
            return TIterator;
        }

        unsigned long EndIndex(PreOrderTreeIterator<T> it){
            return it.vector.size()-1;
        }

        PreOrderTreeIterator<T> end() {
            TIterator.index=EndIndex(TIterator);
            return TIterator;
        }

    private:
        PreOrderTreeIterator<T> TIterator;
    };
    
    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    }



    template<class T>
    class PostOrderTreeIterator: public Helper<T>{
    public:
        PostOrderTreeIterator()=default;
        explicit PostOrderTreeIterator(Tree<T> *new_node){
            PostOrderTree(new_node);
        }
        void PostOrderTree(Tree<T> *new_);
    };
    
    template<class T>
    void PostOrderTreeIterator<T>::PostOrderTree(Tree<T> *new_) {
        if (new_ == nullptr) {
            return;
        }
        else{
            PostOrderTree(new_->left_child_.get());
            PostOrderTree(new_->right_child_.get());
            PostOrderTreeIterator::vector.push_back(new_->value_);
        }
    };

    template <class T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView()=default;
        explicit PostOrderTreeView(Tree<T> *tree) : TIterator(tree){};
        ~PostOrderTreeView()=default;
        PostOrderTreeIterator<T> begin() {
            return TIterator;
        }
        unsigned long EndIndex(PostOrderTreeIterator<T> it){
            return it.vector.size()-1;
        }

        PostOrderTreeIterator<T> end() {
            TIterator.index=EndIndex(TIterator);
            return TIterator;
        }
    private:
        PostOrderTreeIterator<T> TIterator;
    };

    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    };
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
