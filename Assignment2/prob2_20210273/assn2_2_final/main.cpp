#include <iostream>
#include "pizza.h"
#include "customer.h"
#include "rider.h"
#include "vector_rider.h"
#include "vector_customer.h"
#include "Pizza.h"

using namespace std;

int main()
{
	cout << "========================================" << endl;
	cout << "1. Start Pizza Store" << endl;
	Pizza pizza1;
	Pizza pizza2(50000);
	Pizza pizza3(pizza2);
	cout << pizza1 << endl;
	cout << pizza2 << endl;
	cout << pizza3 << endl;

	cout << "========================================" << endl;
	cout << "2. Hire a rider & Enroll a Customer in A place " << endl;
	Rider rider1;
	Customer customer1;
	pizza1.hire(rider1);
	pizza1.enroll(customer1, true);
	cout << pizza1 << endl;

	cout << "========================================" << endl;
	cout << "3. Deliver pizza to All Customers " << endl;
	pizza1.deliver();
	cout << pizza1 << endl;

	cout << "========================================" << endl;
	cout << "4. Hire riders & Enroll customers in B place " << endl;
	Rider riders[] = { rider1, rider1, rider1 };
	Customer customers[] = { customer1, customer1 };
	pizza1.hire(riders, 3);
	pizza1.enroll(customers, 2, false);
	pizza1.deliver();
	cout << pizza1 << endl;

	cout << "========================================" << endl;
	cout << "5. Set Price" << endl;
	pizza1.setPrice(4, 7);
	pizza1.deliver();
	cout << pizza1 << endl;

	cout << "========================================" << endl;
	cout << "6. Check Riders" << endl;
	cout << "Mean money : " << pizza1.meanFee() << endl;
	cout << "Mean time : " << pizza1.meanTimeRiders() << endl << endl;

	cout << "========================================" << endl;
	cout << "7. Check Customers" << endl;
	cout << "Mean money : " << pizza1.meanMoneyCustomers() << endl;
	cout << "Mean time : " << pizza1.meanTimeCustomers() << endl << endl;

	cout << "Resize try" << endl;
	Customer a(199999, 32, 234);
	Vector_Customer K(5, a);
	for (int i = 0; i < K.size(); i++)
	{
		cout << K[i] << endl;
	}
	Rider b;
	Vector_Rider J(5, b);
	for (int i = 0; i < K.size(); i++)
	{
		cout << J[i] << endl;
	}
	K.resize(8);
	J.resize(8);
	for (int i = 0; i < K.size(); i++)
	{
		cout << K[i] << endl;
	}
	for (int i = 0; i < K.size(); i++)
	{
		cout << J[i] << endl;
	}

	cout << "========================================" << endl;
	cout << "1010101010101010" << endl;
	cout << "========================================" << endl;
	cout << "4. Hire riders & Enroll customers in B place " << endl;
	Customer cust[] = { customer1, customer1,customer1, customer1, customer1, customer1, customer1, customer1, customer1, customer1, customer1 , customer1 , customer1 };
	pizza1.enroll(cust, 10, true);
	pizza1.deliver();
	cout << pizza1 << endl;

	return 0;
}