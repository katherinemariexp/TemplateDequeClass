#include <bits/stdc++.h> 
#include "Timer.h"

using namespace std; 


// Driver program to test the Link List Deque class 
int main() { 
	Deque<int> dq; 
	cout << "\nInsert item '5' at tail"; 
	dq.pushTail(5); 

	cout << "\nInsert item '10' at tail"; 
	dq.pushTail(10); 
	cout << "\nRear item: " << dq.getRear(); 

	dq.popTail(); 
	cout << "\nAfter deleting tail item, new tail is "
	     << dq.getRear(); 

	cout << "\nInserting item '15' in head"; 
	dq.pushHead(15); 
	cout << "\nFront item: " << dq.getFront()
		 << "\nNumber of items in Deque: " << dq._size(); 

	dq.popHead(); 
	cout << "\nAfter deleting head item new head is "
		 << dq.getFront();
		 
	dq.popHead(); 
	cout << "\nAfter deleting head item new head is "
		 << dq.getFront();

	cout << "\nInitializing a 10000 item Deque.";
	Timer t1;
	for(int i=1; i<=10000; i++) dq.pushTail(i);
	cout << "\nAdd 1~10000, dq now has " 
		<< dq._size() << " items.";
	double run1 = t1.elapsed();
	cout << "\nTime elipsed: " << run1 << " seconds";

	cout << "\nDeep Copy construct dq2";
	Timer t2;
	Deque<int> dq2( dq );
	double run2 = t2.elapsed();
	cout << "\nTime elipsed: " << run2 << " seconds"
		 << "\ndq2 front to rear: " << dq2.getFront() 
		 << " to " << dq2.getRear();
	cout << "\ndq2[0] is " << dq2[0] 
		 << ", dq2[1000] is " << dq2[1000];
	
	cout << "\nMove construct dq3";
	Timer t3;
	Deque<int> dq3(std::move(dq));
	double run3 = t3.elapsed();
	cout << "\nTime elipsed: " << run3 << " seconds"
		 << "\ndq3 front to rear: " << dq3.getFront() 
		 << " to " << dq3.getRear();
	cout << "\ndq3[0] is " << dq3[0] 
		 << ", dq3[1000] is " << dq3[1000];
		 
	cout << "\nAt this time, dq size is " << dq._size();
} 
