#include <iostream>
#include <cstring>
#include "./../var/variable.h"

#ifndef EXAMPLE_BASE_ARRAY_H
#define EXAMPLE_BASE_ARRAY_H

namespace pelk{

    using namespace std;


    class base_array {

    private:


        void destroy_arr(var arr[], int _length){
            if(_length > 0){
                for(int i = 0; i < _length; i++){
                    arr[i].~var();
                }
                delete arr;
                arr = nullptr;
            }
        }

    public:

        var* array;
        int length = 0;


        base_array(){}

        ~base_array(){}

        void add(var item){

            int old_count = this->length;
            ++this->length;

            var *arr = (var*) operator new (sizeof(var) * (this->length + 1));

            for(int i = 0; i < old_count; i++){
                new (&arr[i]) var(this->array[i]);
            }

            new (&arr[this->length - 1]) var(item);

            this->destroy_arr(this->array, old_count);

            array = (var*) operator new (sizeof(var) * (this->length));

            for(int j = 0; j < this->length; j++){
                new (&array[j]) var(arr[j]);
            }

            destroy_arr(arr, this->length);


        }

        void each(void (*f_ptr)(var index, var item, var someData), var someData = false){
            for(int i = 0; i < this->length; i++){
                (*f_ptr)(i, this->array[i], someData);
            }
        }

        void remove(var index){

        }

        void set(var index, var item){

        }

        void get(var index){

        }



    };

}



#endif //EXAMPLE_BASE_ARRAY_H
