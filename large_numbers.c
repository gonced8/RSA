#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#define PRIME1 1024
#define PRIME2 1024

int compare(char a[], char b[]);


int multiply (char a[], char b[], char r[], int base)
{
    int lena, lenb, lenr;
	int min;
	int i, j, k;
	int n, o;
	int sum;
	int c=0;
	
	lena=strlen(a);
	lenb=strlen(b);
	lenr=lena+lenb;

	if(lena<lenb)
	{	
		min=lena;
	}
	else
	{
		min=lenb;
	}
	
	n=1;
	
	i=lena-1;
	j=lenb-1;
	
	for(k=lenr-1; k>=0; k=k-1)
	{
		sum=c;
		
		for(o=0; o<n; o=o+1)
			sum=sum+(a[i-o]-'0')*(b[j+o]-'0');
		
		r[k]=(sum%base)+'0';
		
		c=(int)(sum/base);
		
		
		if(k<=min)
			n=n-1;
		else if(n<min)
			n=n+1;
		
		if(j>0)
			j=j-1;
		else if(j==0)
			i=i-1;
	}
	
	while(r[0]=='0')
	{
		memmove(r, r+1, (strlen(r)-1)*sizeof(char));
		r[strlen(r)-1]='\0';
	}
	
	return 0;
}


int subtract (char a[], char b[], char r[], int base)
{
	int i, j;
	int m, n;
	int c=0;
	int aux;
	
	i=strlen(a)-1;
	j=strlen(b)-1;
	
	for(; i>=0; i=i-1)
	{
		m=a[i]-'0';
		
		if(j>=0)
		{
			n=b[j]-'0'+c;
			j=j-1;
		}
		else
			n=c;
		
		c=0;
		
		if(n>=base)
		{
			n=n-base;
			c=1;
		}
		
		if(m<n)
		{
			m=m+base;
			c=c+1;
		}
		
		aux=m-n;
		
		r[i]=aux+'0';
	}
	
	while(r[0]=='0' && strlen(r)>1)
	{
		memmove(r, r+1, (strlen(r)-1)*sizeof(char));
		r[strlen(r)-1]='\0';
	}
	
	return 0;
}


int is_factor(char a[], char b[])	/* Returns 1 if a is factor of b or 0 if a is prime of b */
{
	char aux[PRIME1+PRIME2+1]={'\0'};
	
	while(compare(a, b)>=0)
	{
		if(a[0]>b[0])
		{
			
		}
		
		subtract(b, a, aux, 10);

		memmove(b, aux, strlen(aux)*sizeof(char));

		if(strlen(aux)<strlen(b))
		{
			b[strlen(b)-1]='\0';
		}
	}
	
	if(b[0]=='0')
		return 1;	

	return 0;
}


int compare(char a[], char b[])
{
	int lena, lenb;
	int i;
	
	lena=strlen(a);
	lenb=strlen(b);
	
	if(lena>lenb)
		return -1;
	
	else if (lenb>lena)
		return 1;
	
	else if (lena==lenb)
	{
		for(i=0; i<lena; i=i+1)
		{
			if(a[i]>b[i])
				return -1;
			
			else if(a[i]<b[i])
				return 1;
		}
	}
	
	return 0;
}


int mod_small(char a[], char b[])
{
	int len;
	unsigned long int n, d=0;
	int i;
	
	len=strlen(a);
	
	sscanf(b, "%lu", &n);
	
	for(i=0; i<len; i=i+1)
	{
		d=(d*10+(a[i]-'0'))%n;
	}
	
	return d;
}


int sum (char a[], char b[], char r[], int base)
{
	int i, j, k;
	int m, n;
	int c=0;
	unsigned int aux;
	
	i=strlen(a)-1;
	j=strlen(b)-1;
	
	if(i>j)
		k=i;
	else
		k=j;
	
	while(k>=0)
	{
		if(i>=0)
		{
			m=a[i]-'0';
			i=i-1;
		}
		else
			m=0;
		
		if(j>=0)
		{
			n=b[j]-'0'+c;
			j=j-1;
		}
		else
			n=c;
		
		aux=m+n;
		c=(int)(aux/base);
		
		aux=aux%base;
		
		r[k]=aux+'0';
		
		k=k-1;
	}
	
	if(c>0)
	{
		memmove(r+1, r, strlen(r)*sizeof(char));
		r[0]=c+'0';
	}
	
	return 0;
}



int divide_small(char a[], char b[], char r[], int base)
{
	int len;
	unsigned long int n , d=0, aux=0;
	int i=0;
	
	
	len=strlen(a);
	
	sscanf(b, "%lu", &n);
	
	for(i=0; i<len; i=i+1)
	{		
		d=(d*10+(a[i]-'0'));
		
		aux=(int)(d/n);
		
		r[i]=aux+'0';
		
		d=d-aux*n;
	}
	
	while(r[0]=='0' && strlen(r)>1)
	{
		memmove(r, r+1, (strlen(r)-1)*sizeof(char));
		r[strlen(r)-1]='\0';
	}
	
	return 0;
}


int modular_exponentiation(char a[], char b[], char m[], char r[])
{
	mpz_t base, exp, mod, rop;
	
	mpz_init_set_str(base, a, 10);
	mpz_init_set_str(exp, b, 10);
	mpz_init_set_str(mod, m, 10);
	mpz_init(rop);
	
	mpz_powm(rop, base, exp, mod);
	
	r=mpz_get_str(r, 10, rop);

	mpz_clear(base);
	mpz_clear(exp);
	mpz_clear(mod);
	mpz_clear(rop);
	
	return 0;
}

