#include <iostream>
#include <cstring>
#include "./../var/variable.h"

#ifndef EXAMPLE_BASE_ARRAY_H
#define EXAMPLE_BASE_ARRAY_H

namespace pelk {

    using namespace std;


    class base_array {

    private:


        void destroy_arr(var arr[], int _length) {
            if (_length > 0) {
                for (int i = 0; i < _length; i++) {
                    arr[i].~var();
                }
                delete arr;
                arr = nullptr;
            }
        }

        bool __search__(var val) {
            for (int i = 0; i < this->length; i++) {
                var val = this->array[i];
                if (val == val) {
                    return true;
                }
            }
            return false;
        }

    public:

        var *array;
        int length = 0;


        base_array() {}

        ~base_array() {}

        void add(var item) {

            int old_count = this->length;
            ++this->length;

            var *arr = (var *) operator new(sizeof(var) * (this->length + 1));

            for (int i = 0; i < old_count; i++) {
                new(&arr[i]) var(this->array[i]);
            }

            new(&arr[this->length - 1]) var(item);

            this->destroy_arr(this->array, old_count);

            array = (var *) operator new(sizeof(var) * (this->length));

            for (int j = 0; j < this->length; j++) {
                new(&array[j]) var(arr[j]);
            }

            this->destroy_arr(arr, this->length);


        }

        void each(void (*f_ptr)(var index, var item)) {
            for (int i = 0; i < this->length; i++) {
                (*f_ptr)(i, this->array[i]);
            }
        }

        int search(var value) {

            for (int i = 0; i < this->length; i++) {
                var val = this->array[i];
                if (value == val) {
                    return i;
                }
            }
            return -1;

        }

        base_array searchAll(var value){
            base_array arr;
            for (int i = 0; i < this->length; i++) {
                var val = this->array[i];
                if (value == val) {
                    arr.add(i);
                }
            }
            return arr;
        }

        void var_dump() {
            for (int i = 0; i < this->length; i++) {
                cout << this->array[i] << endl;
            }
        }

        void remove(int index) {
            if (index < this->length && this->length != 0) {
                int old_count = this->length;

                var *arr = (var *) operator new(sizeof(var) * (this->length));

                int rem_helper = 0;
                for (int i = 0; i < old_count; i++) {
                    if (index != i) {
                        new(&arr[rem_helper]) var(this->array[i]);
                        rem_helper++;
                    }
                }

                this->destroy_arr(this->array, old_count);
                --this->length;
                array = (var *) operator new(sizeof(var) * (this->length));

                for (int j = 0; j < this->length; j++) {
                    new(&array[j]) var(arr[j]);
                }

                this->destroy_arr(arr, this->length);

            } else {
                cerr << "Index out of range" << endl;
                exit(10);
            }
        }

        void removeAll(var value){
            for (int i = 0; i < this->length; i++) {
                var val = this->array[i];
                if (value == val) {
                    this->remove(i);
                }
            }
        }

        void set(int index, var item) {
            if (index < this->length && this->length != 0) {
                this->array[index] = item;
            } else {
                cerr << "Index out of range" << endl;
                exit(10);
            }
        }

        var *get(int index) {
            if (index < this->length && this->length != 0) {
                return &this->array[index];
            } else {
                cerr << "Index out of range" << endl;
                exit(10);
            }
        }


    };

}


#endif //EXAMPLE_BASE_ARRAY_H
