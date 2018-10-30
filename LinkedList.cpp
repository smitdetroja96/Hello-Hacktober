#include<iostream>
using namespace std;

template<typename E> class List
{
	public:
	//Constructors and destructors
	List(){}
	virtual ~List(){}

	//Return the number of  elements in the list
	virtual int NumberOfElements() = 0;

	//Return the location of Current Element
	virtual int CurrentLocation() = 0;

	//Return the data of current Element
	virtual const E& getData() = 0;

	//clear all the data from the list
	virtual void clear() = 0;

	//insert a data in the List at current Location
	virtual void insert(const E& data) = 0;

	//insert a data in the end of the list
	virtual void append(const E& data) = 0;

	//delete a data at the current location
	virtual E remove() = 0;

	// set the current Location to the start of the List
    virtual void setListLocationToStart() = 0 ;

	// set the current Location to the end of the List
	virtual void setListLocationToEnd() = 0 ;

	// set the current Location to the element on left side of current element
	virtual void previousElement() = 0 ;

	// set the current Location to the element on right side of current element
	virtual void nextElement () = 0 ;

	//Set current Location to a new Location
	virtual void setToNewLocation (int location) = 0 ;
};



template <typename E> class node
{
	public:

        E data;   // stores data for the current node
        node* nextElement;  // points to the next node

		//constructor
        node(const E& dataValue , node* nextElementPointer = NULL)
        {
			data = dataValue;
			nextElement = nextElementPointer;
        }



};



template <typename E> class linkList : public List<E>
{

		node<E>* firstElement;
		node<E>* lastElement;
		node<E>* currentElement;
		int SizeOfList;

	public:

			linkList()
			{
				firstElement = lastElement = currentElement = NULL;
				SizeOfList = 0;
			}

			~linkList()
			{
				for(currentElement = firstElement ; firstElement!=NULL ; firstElement = firstElement->nextElement)
					delete currentElement;

			}

			//Return the number of  elements in the list
			int NumberOfElements()
			{
	 			return SizeOfList;
	 		}

			//Return the location of Current Element
	 		int CurrentLocation()
	 		{
				node<E>* temp = firstElement;
				int count = 1;
				while(temp!=currentElement)
				{
					temp = temp->nextElement;
					count++;
				}
				return count;
	 		}

			//Return the data of current Element
	 		const E& getData()
	 		{
				return currentElement->data;
	 		}

			//clear all the data from the list
	        void clear()
	        {
				setListLocationToEnd();
				node<E>* temp = currentElement;
				while(currentElement!=firstElement)
				{
					previousElement();
					delete temp;
					temp = currentElement;
				}
				firstElement = lastElement = currentElement = NULL;
				SizeOfList = 0;
	        }

	        //insert a data in the List at current Location
	        void insert(const E& data)
	        {
				node<E>* temp = new node<E>(data,NULL);
                if(currentElement == firstElement)
                {
                    temp->nextElement = currentElement;
                    firstElement = currentElement = temp;
                }
                else{
				temp->nextElement = currentElement;
				previousElement();
				currentElement->nextElement = temp;
				currentElement = temp;
				SizeOfList++;
	        }
	        }

	        //insert a data in the end of the list
	 		void append(const E& data)
			{
				node<E>* temp = new node<E>(data , NULL);
				if(SizeOfList==0)
				{
					firstElement = temp;
				}
				else
				{
					setListLocationToEnd();
					currentElement->nextElement = temp;
				}
				lastElement = temp;
				currentElement = lastElement;
				SizeOfList++;
			}

			//delete a data at the current location
	        E remove()
	        {
                if(currentElement == lastElement)
                {
                    previousElement();
                    SizeOfList--;
                    return currentElement->nextElement->data;
                }
                else if(currentElement==firstElement)
                {
                    node<E> *temp = currentElement;
                    nextElement();
                    firstElement = currentElement;
                    return temp->data;
                }
                else{
				node<E>* temp = currentElement;
				previousElement();
				currentElement->nextElement= temp->nextElement;
				currentElement = currentElement->nextElement;
				SizeOfList--;
				return temp->data;
                }
	        }

	        // set the current Location to the start of the List
    		void setListLocationToStart()
    		{
				currentElement = firstElement;
    		}

    		// set the current Location to the end of the List
	        void setListLocationToEnd()
	        {
				currentElement = lastElement;
	        }

	        // set the current Location to the element on left side of current element
			void previousElement()
			{
				node<E>* temp = firstElement;
				while(temp->nextElement != currentElement)
				{
					temp = temp->nextElement;
				}
				currentElement = temp;
			}

	 		// set the current Location to the element on right side of current element
			void nextElement ()
			{
				currentElement = currentElement->nextElement;
			}

			//Set current Location to a new Location
			void setToNewLocation (int location)
			{
				if(location > SizeOfList)
				{
					cout<<"Linked List is not so much lengthy"<<"\n";
				}
				else
				{
				node<E>* temp = firstElement;
				int count = 1;

				while(count<location)
				{
					if(temp==NULL)
					{
						cout << "LinkList is over" <<"\n";
						break;
					}
					temp = temp->nextElement;
					count++;
				}

				currentElement = temp;
				}
			}

			void display()
			{
				node<E>* temp = firstElement;
				while(temp!=NULL)
				{
					cout << temp->data << ">>";
					temp = temp->nextElement;
				}
				cout<<"\n";
			}


};



int main()
{
	linkList<int> A;

	while(1)
	{
		cout<<"1.Size Of LinkList" << "\n" << "2.Get Current Location " << "\n" << "3.Get data at currentLocation"<<"\n" << "4.clear the linkList" << "\n" << "5.Insert at a Position" <<"\n"<< "6.Append The data" << "\n" << "7.remove the data at the position" <<"\n" << "8. Set the location at a first position " << "\n" << "9.  Set the location at a last position " << "\n" <<"10. Set currentElement at a previous Element " << "\n" << "11. Set currentElement at a next Element " << "\n" << "12. set Location to the new Location " << "\n" <<"13.Display the LinkList" << "\n" <<"-1.exit "<< "\n";

		int n;
		cin>>n;

        if(n==1)
          cout<<A.NumberOfElements()<<"\n";

        else if(n==2)
        	cout<<A.CurrentLocation()<<"\n";

        else if(n==3)
        	cout<<A.getData()<<"\n";

        else if(n==4)
        	A.clear();

        else if(n==5)
        {
        	cout<<"Enter the position"<<"\n";
        	int x;
        	cin>>x;
        	A.setToNewLocation(x);
        	cout<<"Enter the data to insert"<<"\n";
        	int p;
        	cin>>p;
        	A.insert(p);
        }

        else if(n==6)
        {
			cout<<"Enter the data to insert"<<"\n";
        	int p;
        	cin>>p;
        	A.append(p);
        }

        else if(n==7)
        {
			cout<<"Enter the position"<<"\n";
        	int x;
        	cin>>x;
        	int p;
        	A.setToNewLocation(x);
        	//cout<<"hii";
        	if(x<A.NumberOfElements())
        	{
        		p = A.remove();
        		cout<<"removed data is " << p << "\n";
        	}
        }

        else if(n==8)
        	A.setListLocationToStart();

        else if(n==9)
        	A.setListLocationToEnd();

        else if(n==10)
        	A.previousElement();

        else if(n==11)
        	A.nextElement();

        else if(n==12)
        {
			cout<<"Enter the position"<<"\n";
        	int x;
        	cin>>x;
        	A.setToNewLocation(x);
        }

        else if(n==13)
      		A.display();

        else if(n==-1)
        	return 0;
	}
	return 0;
}
