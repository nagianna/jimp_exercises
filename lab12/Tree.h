//
// Created by Ania on 2018-05-29.
//
#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>
#include <stack>

namespace tree {

    template<class T>
    class Tree {
    public:
        Tree *root_;
        std::unique_ptr<Tree<T>> left_child_;
        std::unique_ptr<Tree<T>> right_child_;
        T value_;


    public:
        Tree() {};

        Tree(const T &Element) {
            root_ = this;
            value_ = Element;
            left_child_ = nullptr;
            right_child_ = nullptr;
        }

        ~Tree() {};

        T Value()const {
            return value_;
        }


        void Insert(const T &Element) {
            if (root_->value_ > Element) {
                if (!root_->left_child_) {
                    root_->left_child_ = std::make_unique<Tree<T>>(Element);
                } else {
                    root_->left_child_->Insert(Element);
                }
            } else {
                if (!root_->right_child_) {
                    root_->right_child_ = std::make_unique<Tree<T>>(Element);
                } else {
                    root_->right_child_->Insert(Element);
                }
            }

        }


        size_t Depth() {
            if (root_->left_child_ == nullptr || root_->right_child_ == nullptr) {
                if (root_->left_child_ != nullptr) {
                    return 1 + left_child_->Depth();
                }
                if (root_->right_child_ != nullptr){
                    return 1 + right_child_->Depth();
                }
                return 1;
            }
            else {
                auto left = left_child_->Depth();
                auto right = right_child_->Depth();
                if (left > right) {
                    return 1 + left;
                }
                else {
                    return 1 + right;
                }
            }
        }


        size_t Size() {
            size_t size = 1;

            if (root_->left_child_ != nullptr) {
                size += left_child_->Size();
            }
            if (root_->right_child_ != nullptr) {
                size += right_child_->Size();
            }

            return size;

        };

        Tree<T> *Root() {
            return this;
        }

    };

}

#endif //JIMP_EXERCISES_TREE_H
