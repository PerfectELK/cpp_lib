#include "./../var/variable.h"
#include <iostream>

#ifndef EXAMPLE_BASE_ARRAY_H
#define EXAMPLE_BASE_ARRAY_H

namespace pelk{

    using namespace std;

    class base_array {

    private:

        int count;

    public:

        var *array[0];
        int length = 0;


        base_array(){

            this->count = 0;
        }

        ~base_array(){}

        void add(var item){
            int old_count = this->length;
            this->length++;

            var *arr[this->length];
            for(int i = 0; i < old_count; i++){
                cout << this->array[i] << endl;
                //*arr[i] = this->array[i];
            }

            arr[this->count - 1] = &item;


        }

        void remove(var index){

        }

        void set(var item){

        }

        void get(var index){

        }



    };

}



#endif //EXAMPLE_BASE_ARRAY_H
