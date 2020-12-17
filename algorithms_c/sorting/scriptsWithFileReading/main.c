#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "bubble.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "selection.h"
#include "shaker.h"
#include "shell.h"

int main(int argc, char* argv[]){
	
	/* declare variables */
	unsigned int number_of_items = 1000;
	char file_name[50];
	FILE* fp;
	char line[256];
	size_t len = 0;
	ssize_t read;
	long* data;
	unsigned int count = 0;
	char sort_type[20] = "bubble";
	char number_of_items_string[10] = "1k";
	clock_t start, end;
	double cpu_time_used = 0;
	
	if(argc > 1){	
		if(argc > 2){
			strncpy(number_of_items_string, argv[2], 10);
		}
		strncpy(sort_type, argv[1], 50);
		if(strcmp(number_of_items_string, "1k") == 0){
			number_of_items = 1000;
		}else if(strcmp(number_of_items_string, "2k") == 0){
			number_of_items = 2000;
		}else if(strcmp(number_of_items_string, "3k") == 0){
			number_of_items = 3000;
		}else if(strcmp(number_of_items_string, "4k") == 0){
			number_of_items = 4000;
		}else if(strcmp(number_of_items_string, "5k") == 0){
			number_of_items = 5000;
		}else if(strcmp(number_of_items_string, "6k") == 0){
			number_of_items = 6000;
		}else if(strcmp(number_of_items_string, "7k") == 0){
			number_of_items = 7000;
		}else if(strcmp(number_of_items_string, "8k") == 0){
			number_of_items = 8000;
		}else if(strcmp(number_of_items_string, "9k") == 0){
			number_of_items = 9000;
		}else{
			number_of_items = 1000;
		}
	}
	printf("Sort type = %s and number of items is %s\n", sort_type, number_of_items_string);
	/* generate file name */
	sprintf(file_name, "../../../generatingData/data/long/long%d.txt", number_of_items);
	
	fp = fopen(file_name, "r");
	data = calloc(number_of_items, sizeof(long));
	
	while(fgets(line, sizeof(line), fp)){
		data[count] = atoi(line);
		count++;
	}
	
	fclose(fp);

	printf("before:\n");
	for(int i = 0; i < number_of_items; i++){
		// printf("%ld, ", data[i]);
	}
	
	/* Sort based on type */
	if(strcmp(sort_type, "bubble") == 0){
		start = clock();
		bubble_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "heap") == 0){
		start = clock();
		heap_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "insertion") == 0){
		start = clock();
		insertion_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "merge") == 0){
		start = clock();
		merge_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "quick") == 0){
		start = clock();
		quick_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "selection") == 0){
		start = clock();
		selection_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "shaker") == 0){
		start = clock();
		shaker_sort(data, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else if(strcmp(sort_type, "shell") == 0){
		start = clock();
		shell_sort(data, 0, number_of_items);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}else{
		printf("incorrect sort_type entered\n");
	}
	
	printf("after:\n");
	for(int i = 0; i < number_of_items; i++){
		// printf("%ld, ", data[i]);
	}
	
	printf("Time taken is %f seconds\n", cpu_time_used);
	free(data);
	
	return 0;
}
