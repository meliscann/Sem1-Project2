#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func_dec_to_bin(int num) {  // 1. question
	int arr[8]={0,0,0,0,0,0,0,0};
	int i=1;
	int j=0;
	int k=6;
	int x=64; 
	int carry=0;
	
	if(num>0) {
		while(i<8) {
		while(num>=x) {
			arr[i]=1;
			num=num-x;
		}
		x=x/2;
		i++;
	}
	}
	
	if(num<0) {
		num=-num;
		while(i<8) {
		while(num>x) {
			arr[i]=1;
			num=num-x;
		}
		x=x/2;
		i++;
	}
	
	while(j<8) {
		if(arr[j]==1) {
			arr[j]--;
		}
		else {
			arr[j]++;
		}
		j++;
	}	
	
	arr[7]+=1;
	if(arr[7]==2) {
		arr[7]=0;
		carry=1;
		while(k>=0) {
		if(arr[k]==2) {
			arr[k]=0;
			carry=1;
		}
		else { 
		arr[k]=1;
		carry=0;
		}
		k--;
	}	
	}
	}
	
	return printf("%d%d%d%d %d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
}


    int func_bin_to_dec(int bin[]) {  // 2. question
    int dec;
    int i=1;
    if(bin[0]==1) {
        dec=-128;
        while(i<8) {
            if(bin[i]==1) {
                dec = dec + pow(2,7-i);
            }
            i++;
        }
    }
    else if(bin[0]==0){
        dec=0;
        while(i<8) {
            if(bin[i]==1) {
                dec = dec + pow(2,7-i);
            }
            i++;
        }
    }
    return dec;
}


void bin_add(int bin1[], int bin2[], int result[]) {  // 3. question
	int i=7;
	int carry=0;
	
	while(i>=0) {
		result[i]=(bin1[i]+bin2[i]+carry) % 2;
		carry=(bin1[i]+bin2[i]+carry) / 2;
		i--;
	}
	
	if(carry==1) {
		i=7;
		while (i>=0) {
            if (result[i]==1) {
                result[i]=0;
            } else {
                result[i]=1;
                break;
            }
            i--;
        }
        
        if (result[0]==0) {
            result[0]=1;
        } else {
            result[0]=0;
        }
	}
}


int menu(int x, int y, int z) {  // 5. question
	float result;
	if(z==1)
	result=x+y;
	if(z==2) 
	result=x*y;
	if(z==3)
	result=x/y;
	
	return result;
}


int main() {
	int i=0;
	int num;
	int num2;
	int bin[8];
	int bin1[8] = {0,0,0,1,1,0,0,0}; // 24
    int bin2[8] = {0,0,0,0,0,1,0,1}; // 5
    int result[8] = {0,0,0,0,0,0,0,0};
    int multi_result[8] = {0,0,0,0,0,0,0,0};
    int x,y,z;
    int add[8];
    int list1[8] = {0,0,0,1,1,0,0,0}; //24
    int list2 = {0,0,0,1,1,0,0,0}; //5
	
	printf("Please enter the first number between -127 and 128 inclusive: \n"); // 1. question
	scanf("%d", &num);
	printf("Please enter the second number between -127 and 128 inclusive: \n");
	scanf("%d", &num2);
	printf("First number in 8-bit binary: ");
	func_dec_to_bin(num);
	printf("\n");
	printf("Second number in 8-bit binary: ");
	func_dec_to_bin(num2);
	printf("\n");
	
	
	
	printf("Please enter 8-bit binary number: \n");  // 2. question
    while(i<8) {
        scanf("%d", &bin[i]);
        i++;
    }
    int dec = func_bin_to_dec(bin);
    printf("Your binary number in decimal is: %d \n", dec);
    
    
    
    bin_add(bin1, bin2, result);  // 3. question
    printf("Binary representation of the summation: %d%d%d%d %d%d%d%d\n", result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7]);
    
    
    printf("Please choose an option: Addition(1), Multiplication(2), Division(3) \n");  // 5. question
    scanf("%d", &z);
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);
    printf("Result is: %d \n", menu(x,y,z));
	
	
	return 0;
}
	
	
