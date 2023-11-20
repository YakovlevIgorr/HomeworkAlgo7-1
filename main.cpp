#include <iostream>
#include <fstream>


void open(int* array[], int size_array){

    std::ifstream input;
    input.open("input.txt");
    if(input) {
        input.seekg(2, std::ios_base::beg);
        for (int i = 0; i < size_array; i++) {
            for (int k = 0; k < size_array; k++) {
                input >> array[i][k];
            }
        }
    }else std::cout << "Error open file";

}

void deep(int* array[], int* array_count, int size_array, int pic){//Порядок обхода вершин: 1 3 2 4 5 7 6
    array_count[0] = pic;
    for(int i = 0; i < size_array; i++){
        for(int k = 0; k < size_array; k++){

            if(array[k][pic - 1] == 1 && array[0][k] != 7){//посмотреть нужен ли второй for
                array_count[i + 1] = k + 1;
                array[0][pic - 1] = 7;
                pic = k + 1;
                break;
            }
        }
    }

    }


void print(int* array[], int size_array){
    for(int i = 0; i < size_array; i++){
        for(int k = 0; k < size_array; k++) {
            std::cout << array[i][k] << "  ";
        }
        std::cout << "\n";
    }
}

void print_array(int* array, int size){
    std::cout << "\nПорядок обхода вершин: ";
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int size_array;
    std::ifstream input;
    input.open("input.txt");
    input >> size_array;


    int* array_count = new int[size_array];
    int pic = 1;//с какой вершины начать поиск
    int** array = new int*[size_array];
    for(int i = 0; i < size_array; i++){
        array[i] = new int[size_array];
    }

    open(array, size_array);
    print(array, size_array);
    deep(array, array_count,size_array, pic);
    print_array(array_count,size_array);
    //print(array, size_array);

    delete[] array_count;
    for(int i = 0; i < size_array; i++){
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
