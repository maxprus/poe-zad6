#include <iostream>	
using namespace std;
#include <unistd.h>	
#include "base.hpp"
int main()
{
	CTemperatureSensor TemperatureSensor(-100, 100);
	CHumiditySensor HumiditySensor(0, 100);		
	CPressureSensor PressureSensor(900, 1200);
	CWindSensor WindSensor(0, 100);
	CInsolationSensor InsolationSensor(0, 100);
	CBase Base1(3);					
	
	try
	{
		Base1.setSensor(&TemperatureSensor);		
	}
	catch (CException& e)
	{
		cout << "Adding sensors failed with message: " << e.GetMessage() << endl;
	}
	
	CBase Base2(3);
	Base2 = Base1;
	try
	{
		Base1.setSensor(&HumiditySensor);
		Base1.setSensor(&PressureSensor);
		Base2.setSensor(&WindSensor);
		Base2.setSensor(&InsolationSensor);
	}
	catch (CException& e)
	{
		cout << "Adding sensors failed with message: " << e.GetMessage() << endl;
	}
	while(true)					
	{		
		cout << "B1" << endl;
		Base1.displayMeasurements();
		cout << "B2" << endl;
		Base2.displayMeasurements();
		sleep(3);				
	};

	return 0;
}
