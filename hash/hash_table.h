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

        static void eachKeyCompare(var index, var item, var someData, hash_table &ctx){
            if(item == someData){
                ctx.compare_index = index;
            }
        }

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


        ~hash_table(){
            delete arr;
            arr = nullptr;
            delete keys;
            keys = nullptr;
        }


    };
}



#endif //EXAMPLE_HASH_TABLE_H
