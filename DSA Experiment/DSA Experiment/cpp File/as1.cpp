#include<iostream>
#include<string.h>
using namespace std;

class HashFunction
  {
     typedef struct hash
	{
		long key;
		char name[10];
	}hash;
	hash h[10];
   public:
	HashFunction();
	void insert();
	void display();
	int find(long);
	void Delete(long);


  };

HashFunction::HashFunction()
  {
	int i;
	for(i=0;i<10;i++)
	  {
		h[i].key=-1;
		strcpy(h[i].name,"NULL");
	  }
  }
void HashFunction::Delete(long k)
  {
	int index=find(k);
	if(index==-1)
	  {
		cout<<"\n\tKey Not Found";
	  }
	else
	  {
		h[index].key=-1;
		strcpy(h[index].name,"NULL");
		cout<<"\n\tKey is Deleted";
	  }
	
	
  }
int HashFunction::find(long k)
  {
	int hi,i;
	hi=k%10;
	if(hi!=-1 && k==h[hi].key)
	{
	cout<<"\n\t"<<h[hi].key<<" is Found at "<<hi<<" Location With Name "<<h[hi].name;
	return hi;
	}
	else if(hi!=-1)
	{
		for(i=hi+1;i!=hi;i=(i+1)%10)
		{
			if(k==h[i].key)
			{
				cout<<"\n\t"<<h[i].key<<" is Found at "<<i<<" Location With Name "<<h[i].name;
				return i;
			}
		
		}
	}
	else
	{
			return -1;
	}

}

	
void HashFunction::display()
  {
	int i;
	cout<<"\n\t\tKey\t\tName";
	for(i=0;i<10;i++)
 	  {
		cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].name;
	  }
  }

void HashFunction::insert()
  {
	char ans,n[10],ntemp[10];
	long k,temp;
	int hi,cnt=0,flag=0,i;
	
	do
	  {
		if(cnt>=10)
		  {
			cout<<"\n\tHash Table is FULL";
			break;
		  }
		cout<<"\n\tEnter a Telephone No: ";
		cin>>k;
		cout<<"\n\tEnter a Client Name: ";
		cin>>n;
		hi=k%10;// hash function
		if(h[hi].key==-1)
		  {
			h[hi].key=k;
			strcpy(h[hi].name,n);
		  }
	     else
 		  {
 		  	cout<<"\n Collision occurs......use collision resolution stratergy";
			
			if(h[hi].key%10!=hi)
			  {
			  	cout<<"\n *****Collision with replacement******";
				temp=h[hi].key;
				strcpy(ntemp,h[hi].name);
				h[hi].key=k;
				strcpy(h[hi].name,n);
				for(i=hi+1;i<10;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						flag=1;
						break;
				   	  }
			  	  }
				for(i=0;i<hi && flag==0;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						break;
				   	  }
			         }
		  	  }
			else
			  {
			  	cout<<"\n *****Collision without replacement******";
				for(i=hi+1;i<10;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=k;
						strcpy(h[i].name,n);
						flag=1;
						break;
				   	  }
			  	  }
				for(i=0;i<hi && flag==0;i++)
			  	  {
					if(h[i].key==-1)
				  	  {
						h[i].key=k;
						strcpy(h[i].name,n);
						break;
				   	  }
			       }
			  }	
			
		  }
	    	flag=0;
	     cnt++; 
	     cout<<"\n\t..... Do You Want to Insert More Key: ";
	     cin>>ans;
	  }while(ans=='y'||ans=='Y');
	
  }
			


int main()
  {
	long k;
	int ch,index;
	char ans;
	HashFunction obj;
	do
	  {
		cout<<"\n\t***** Dictionary (ADT) *****";
		cout<<"\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
		cout<<"\n\t..... Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		  {
			case 1: 	obj.insert();
					break;
			case 2:	obj.display();
					break;
			case 3:	cout<<"\n\tEnter a Key Which You Want to Search: ";
					cin>>k;			
					index=obj.find(k);
					if(index==-1)
					  {
						cout<<"\n\tKey Not Found";
					  }
					break;
			case 4:	cout<<"\n\tEnter a Key Which You Want to Delete: ";
					cin>>k;			
					obj.Delete(k);
					break;
			case 5:
					break;
		  }
		cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
  }
