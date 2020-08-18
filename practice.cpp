#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long n){
	
	// Function to calculate a^b mod n
	if(b==0) return 1;

	long long s=power(a,b/2,n);
	if(b&1)
		return (a%n*(s%n*s%n)%n)%n;
	
	else
		return (s%n*s%n)%n;
	
}

bool miller_rabin(long long n, long long a){
	
	//to check whether a given number is prime or not
	
	
	if(n==2|| n==3|| n==5|| n==7|| n==11) return true;
	

	if(n%2==0) return false;

	// If N is even, it cannot be prime

	long long k = 0;
	
	for(long long i=0; i<=31; i++){
		if((n-1)%(1<<i))break;
		else k=i;
	}

	// We go till 31, because the limit of int is 2^31-1
	
	long long m = (n-1) / (1 << k);

	// Calculate P = a^m mod n

	long long P = powmod(a,m,n);
	
	// If P is '1' or '-1' n is a strong pseudo-prime
	if(P== 1 || P==n-1) return true;
	
	for(int i=1; i<k; i++){

		// k-1 is the maximum number of steps

		P=power(P,2,n);

		// We calculate P =P*P mod n

		if(P==1) return false;

		// N passes Fermats test
		// But does not pass Square Root Test

		if(P==n-1) return true;
		// N will eventually pass the Fermat test
		// And the Square Root Test
	}
	return false;
}

bool isPrime(long long n){
	long long base[] = {2,3,5,7,11};
	

	for(int i=0; i<5; i++){
		if(!miller_rabin(n, base[i])) return false;
		
	}

	return true;
}

int main(){
	long long n;
	cin >> n;
	if(isPrime(n)) cout << "PRIME";
	else cout << "NOT PRIME";
	return 0;
}