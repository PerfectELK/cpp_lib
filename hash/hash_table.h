//
// Created by pelk on 03.09.2019.
//
#include "./../array/base_array.h"

#ifndef EXAMPLE_HASH_TABLE_H
#define EXAMPLE_HASH_TABLE_H

namespace pelk{

    class hash_table {

    private:

        base_array *arr;
        base_array *keys;


        int compare_index;

    public:

        hash_table(){
            arr = new base_array();
            keys = new base_array();
        }

        void put(var key, var value){
            this->keys->add(key);
            this->arr->add(value);
        }

        void remove(var key){
            int index = this->keys->search(key);
            if(index != -1){
                this->keys->remove(index);
                this->arr->remove(index);
            }
        }

        void removeAll(var key){
            base_array indexes = this->keys->searchAll(key);
            if(indexes.length > 0){
                for(int i = 0; i <= indexes.length; i++){
                    var index = indexes.get(i);
                    this->keys->remove(index);
                    this->arr->remove(index);
                }
            }
        }

        void var_dump(){
            for(int i = 0; i < this->keys->length; i++){
                cout << "--";
                cout << this->keys->get(i);
                cout << "-->";
                cout << this->arr->get(i) << endl;
            }
        }


        ~hash_table(){
            delete arr;
            arr = nullptr;
            delete keys;
            keys = nullptr;
        }


    };
}



#endif //EXAMPLE_HASH_TABLE_H
