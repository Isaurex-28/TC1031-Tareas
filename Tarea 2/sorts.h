#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <class T>
    class Sorts{
        private:
            void swap(std::vector<T>&, int, int);
            void copyArray(std::vector<T>&, std::vector<T>&, int, int);
            void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
            void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);

        public:
            void ordenaSeleccion(std::vector<T>&);
            void ordenaBurbuja(std::vector<T>&);
            void ordenaMerge(std::vector<T>&);
            int busqSecuencial(std::vector<T>&, int);
            int busqBinaria(std::vector<T>&,int);
            
    };

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for(int i = low; i <= high; i++){
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &source) {
	for(int i = source.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(source[j] > source[j+1]){
				swap(source, j ,j+1);
			}
		}
	}
}

template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &source) {
	int max;
	for (int i = source.size() - 1; i > 0; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (source[j] > source[max]) {
				max = j;
			}
		}

		if (max != i) {
			swap(source, i, max);
		}
	}
}


template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;

	while(i <= mid && j <= high){
		if(A[i] < A[j]){
			B[k] = A[i];
			i++;
		}
		else{
			B[k] = A[j];
			j++;
		}
		k++;

	}
	if(i > mid){
		while(j <= high){
			B[k++] = A[j];
			j++;
		}
	}
	else{
		while(i <= mid){
			B[k++] = A[i];
			i++;
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &source) {
	std::vector<T> tmp(source.size());
	
		mergeSplit(source, tmp, 0, source.size() - 1);

}

template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> &source,int num){
    for(int i = 0; i <= source.size()-1; i++){
        if(num == source[i]){
            return i;
        }
    }

    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(std::vector<T> &source, int num){
	int mid;
	int low = 0;
	int high = source.size() - 1;

	while(low < high){
		mid = (high + low)/2;
		if(source[mid] == num){
			return mid;
		}
		else if(source[mid] < num){
			low = mid + 1;
		}
		else if(source[mid] > num){
			high= mid - 1;
		}
	}
	return -1;
}


#endif
