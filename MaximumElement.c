#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float MaxElement(float*, int);
float MinElement(float*, int);

int main(){
	int n, length;
	float temp, *nums;
	
	printf("Please enter count of the numbers: ");
	scanf("%d", &length);
	
	printf("--------------------------------------\n");
	nums = (float*) malloc(length * sizeof(float));
	for(n = 0; n < length; n++){
		printf("[%d]: ", n+1);
		scanf("%f", &temp);
		nums[n] = temp;
	}
	printf("--------------------------------------\n");
	
	printf("Maximum found is %f.\n", MaxElement(nums, length));
	printf("Minimum found is %f.", MinElement(nums, length));
	
	getch();
	return 0;
}

float MaxElement(float *elements, int length){
	float r = elements[0];
	int i;
	for(i = 1; i < length; i++)
		if(r < elements[i])
			r = elements[i];
	return r;
}

float MinElement(float *elements, int length){
	float r = elements[0];
	int i;
	for(i = 1; i < length; i++)
		if(r > elements[i])
			r = elements[i];
	return r;
}
