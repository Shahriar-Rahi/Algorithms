//https://www.programiz.com/cpp-programming/library-function
#include <cstdlib>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;
	return (*x - *y);
}

int main()
{
	const int num = 10;
	int arr[num] = {5,9,10,14,16,19,21,26,29,31};
	int key1 = 10;
	int *p1 = (int*)bsearch(&key1,arr,num,sizeof(int),compare);

	if(p1 == NULL)
		cout << key1 << " not found " << endl;
	else
		cout << key1 << " found at position " << (p1-arr) << endl;

	int key2 = 15;
	int *p2 = (int*)bsearch(&key2,arr,num,sizeof(int),compare);
	if(p2 == NULL)
		cout << key2 << " not found " << endl;
	else
		cout << key2 << " found at position " << (p2-arr) << endl;
		
	cout << "Before sorting" << endl;
	for (int i=0; i<num; i++)
		cout << arr[i] << " ";

	qsort(arr,num,sizeof(int),compare);
	cout << endl << endl;
	cout << "After sorting" << endl;

	for (int i=0; i<num; i++)
		cout << arr[i] << " ";
		
	double x = 14.86, intPart, fractPart;
	
	fractPart = modf(x, &intPart);
	cout << x << " = " << intPart << " + " << fractPart << endl;
	
	x = -31.201;
	fractPart = modf(x, &intPart);
	cout << x << " = " << intPart << " + " << fractPart << endl;
	
	srand(time(0));
	int random = rand();

	cout << "Seed = " << time(0) << endl;
	cout << "Random number = " << random << endl;
	
	cout << "Number in String = " << "    13" << endl;
	cout << "Number in Long Int = " << atol("    13") << endl << endl;
	
	cout << "Number in String = " << "  25    " << endl;
	cout << "Number in Long Int = " << atol("  25    ") << endl << endl;
	
	cout << "Number in String = " << "41.90abcd" << endl;
	cout << "Number in Long Int = " << atol("41.90abcd") << endl << endl;
	
	// Returns 0 because of invalid conversion
	cout << "abcd14" << " to Long Int = " << atol("abcd14") << endl;
	
	int base = 10;
    char str[] = "27ab_1x";
    char *end; 
    long int num;
    
    num = strtol(str, &end, base);
    cout << "Number in  String = " << str << endl;
    cout << "Number in Long Int = " << num << endl;
    cout << "End String = " << end << endl << endl;
    
    // the pointer to invalid characters can be null
    strcpy(str, "27");
    cout << "Number in  String = " << str << endl;
    num = strtol(str, &end, base);
    cout << "Number in Long Int = " << num << endl;
    if (*end) {
        cout << end;
    } else {
        cout << "Null pointer";
    }
	
	char numberString[] = "-32.40"; 
	double numberInDouble;
	cout << "Number in  String = " << numberString << endl;

	numberInDouble = atof(numberString);
	cout << "Number in Double = " << numberInDouble;
	
	char str[] = "parrot,owl,sparrow,pigeon,crow";
    char delim[] = ",";
    cout << "The tokens are:" << endl;
    char *token = strtok(str,delim);
    while (token)
    {
        cout << token << endl;
        token = strtok(NULL,delim);
    }
    
    char str[] = "Use your brain and heart";
    char target[] = "brain";
    char *p = strstr(str, target);
    
    if (p)
        cout << "'" << target << "' is present in \"" << str << "\" at position " << p-str;
    else
        cout << target << " is not present \"" << str << "\"";
	return 0;
}
