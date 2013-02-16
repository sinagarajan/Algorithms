# include <iostream>

using namespace std;

int stringLength(char *value)
{
	int length=0;
	while(*(value+length)!='\0')
		length++;
	return length;
}

void stringReverse(char* value,int length)
{
	char temp,*front,*last;	
	int itr=0;
	front=value;
	last=value;
	while(itr<length-1)
	{
		last++;
		itr++;
	}
	while(front<last)
	{

		temp=*front;
		*front=*last;
		*last=temp;
		++front;
		--last;		
	}
}

void stringPartreverse(char *begin,char *end)
{
	char temp;
	while(begin<end)
	{
		temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;end--;
	}
}
void wordReverse(char *value)
{
	char *itr=value;
	char *front=value;
	while(*itr)
	{
		itr++;
		if((*itr )==' ')
		{
			stringPartreverse(front,itr-1);
			front=itr+1;
		}
		else if((*itr)=='\0')
		{
			stringPartreverse(front,itr-1);
		}
	
	}
	int length=stringLength(value);
	stringReverse(value,length);
}

int main()
{

	char sample[]="siva is my name";
	wordReverse(sample);
	cout<<sample;
}
