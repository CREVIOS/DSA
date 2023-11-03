#include<stdio.h>
#include <stdlib.h>

struct vector{
	int* data;
	int size, capacity;
	
	vector(int cap){
		data = (int*)malloc(cap * sizeof(int));
		size = 0;
		capacity = cap;
	}
	void push_back(int value){
		if(size==capacity){
			capacity *= 2;
			data = (int*) realloc(data, capacity * sizeof(int));
		}
		data[size++] = value;
	}
	
	int get(int index){
		if(index>=size){
		fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
		}
		return data[index];
	}
	int contains(int value){
		for(int i = 0; i < size;i++){
			if(get(i)==value){
				return i;
			}
		}
		return size;
	}
	void remove(int value){
		int id = contains(value);
		if(id!=size){
			for(int i = id;i<size-1;i++){
				data[i] = data[i+1];
			}
			size--;
		}
	}
	void clear(){
		free(data);
		size = 0;
		capacity = 0;
	}
	
};
	
int main(){
	int n;
	scanf("%d",&n);
	vector v = vector(n);
	int p = n;
	while(p--){
	    int a;
	   scanf("%d",&a);
	   v.push_back(a);
	}
	for(int i = 0; i < n;i++){
		printf("%d\n",v.get(i));
	}
	v.remove(4);
	n = v.size;
		for(int i = 0; i < n;i++){
		printf("%d\n",v.get(i));
	}
}