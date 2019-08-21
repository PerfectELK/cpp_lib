#include "./../var/variable.h"
#include <iostream>
#include <cstring>

#ifndef EXAMPLE_BASE_ARRAY_H
#define EXAMPLE_BASE_ARRAY_H

namespace pelk{

    using namespace std;

    class base_array {

    private:



    public:

        var **array = new var*[0];
        int length = 0;


        base_array(){}

        ~base_array(){}

        void add(var item){
            int old_count = this->length;
            this->length++;

            var *arr[this->length];
            for(int i = 0; i < old_count; i++){
                arr[i] = this->array[i];
            }

            arr[this->length - 1] = &item;

            delete[] this->array;
            array = nullptr;
            array = new var*[this->length];
            for(int j = 0; j < this->length; j++){
                array[j] = arr[j];
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
