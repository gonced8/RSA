#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME1 1024
#define PRIME2 1024
#define PUBLIC 20

int multiply (char a[], char b[], char result[], int base);
int subtract (char a[], char b[], char r[], int base);
int calculate_totient (char prime1[], char prime2[], char totient[]);
int is_factor(char a[], char b[]);
int compare(char a[], char b[]);
int mod_small(char a[], char b[]);
int get_private (char totient[], char public[], char private[]);
int sum (char a[], char b[], char r[], int base);
int divide_small(char a[], char b[], char r[], int base);
int is_prime(unsigned long int number);


int generate_keys (int argc, char **argv)
{
	char prime1[PRIME1+1] = {'0'};
	char prime2[PRIME2+1] = {'0'};
	char n[PRIME1+PRIME2+1]={'0'};
	char totient[PRIME1+PRIME2+1]={'\0'};
	char public[PUBLIC+1]={'\0'};
	char private[PRIME1+PRIME2+1]={'\0'};
	int comp=0;
	
	printf("\nInsert first prime number:\n");
	getchar(); /* To clean buffer */
	fgets(prime1, PRIME1, stdin);
	prime1[strlen(prime1)-1]='\0';
	
	printf("\nInsert second prime number:\n");
	fgets(prime2, PRIME2, stdin);
	prime2[strlen(prime2)-1]='\0';
	
	multiply(prime1, prime2, n, 10);
	printf("\nn = %s\n", n);
	
	calculate_totient(prime1, prime2, totient);
	printf("\ntotient = %s\n", totient);
	
	while(1)
	{
		memset(public, '\0', strlen(public)*sizeof(char));
		memset(private, '\0', strlen(private)*sizeof(char));

		printf("\nInsert public key:\n");
		fgets(public, PUBLIC, stdin);
		public[strlen(public)-1]='\0';
		
		while(is_prime((unsigned long int)atol(public))==0 || mod_small(totient, public)==0 || compare(public, totient)<0)
		{
			printf("\nInvalid public key. Try another.\n");
			memset(public, '\0', PUBLIC);
			fgets(public, PUBLIC, stdin);
			public[strlen(public)-1]='\0';
		}
		
		printf("\nPublic key: %s\n", public);
		
		get_private(totient, public, private);
		
		printf("\nPrivate key: %s\n", private);
		
		comp=compare(public, private);
		
		if(comp==0)
		{
			printf("\nPublic key and private key match. Try another public key.\n\n");
			continue;
		}
		
		break;
	}
	
	return 0;
}


int calculate_totient (char prime1[], char prime2[], char totient[])
{
	char aux1[PRIME1+1] = {'\0'};
	char aux2[PRIME2+1] = {'\0'};
	
	memmove(aux1, prime1, strlen(prime1)*sizeof(char));
	memmove(aux1, prime1, strlen(prime1)*sizeof(char));
	
	subtract(prime1, "1", aux1, 10);
	subtract(prime2, "1", aux2, 10);
	
	multiply(aux1, aux2, totient, 10);
	
	return 0;
}



int get_private (char totient[], char public[], char private[])
{
	unsigned long int k=1;
	char ck[PUBLIC+1]={'\0'};
	char aux[PRIME1+PRIME2+PUBLIC+1]={'\0'};
	char aux2[PRIME1+PRIME2+PUBLIC+1]={'0'};
	
	ck[0]='1';
	
	for(k=1; ; k=k+1)
	{
		memset(ck, '\0', 4*sizeof(char));
		sprintf(ck, "%lu", k);
		
		multiply(ck, totient, aux, 10);
		
		sum(aux, "1", aux, 10);
		
		if(mod_small(aux, public)==0)
			break;
	}
	
	printf("\nk=%lu\n", k);
	
	divide_small(aux, public, aux2, 10);
	
	memmove(private, aux2, strlen(aux2)*sizeof(char));
	
	return 0;
}


int is_prime(unsigned long int number)
{
	int t;
	unsigned long int n3, j;
	
	t=1;
	
	n3=(unsigned long int)(sqrt(number));
	
	for(j=2; j<=n3; j=j+1)
	{
		if(number%j==0)
		{
			t=0;
			break;
		}
	}
	
	return t;
}
