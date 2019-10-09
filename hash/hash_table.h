//
// Created by pelk on 03.09.2019.
//

#ifndef hash_table_h
#define hash_table_h

#include "./../array/base_array.h"



namespace pelk{

    class hash_table {

    private:

    public:

        base_array *arr;
        base_array *keys;


        int compare_index;

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

        void var_dump(int deep = 0){
            for(int i = 0; i < this->keys->length; i++){
                for(int j = 0; j < deep; j++){
                    cout << "-";
                }
                cout << "- ";
                cout << this->keys->get(i);
                cout << "-> ";
                cout << this->arr->get(i) << endl;
            }
        }


        ~hash_table(){
            // pizdec ebaniy cpp
            // delete arr;
            // arr = nullptr;
            // delete keys;
            // keys = nullptr;
        }


    };
}



#endif //EXAMPLE_HASH_TABLE_H
