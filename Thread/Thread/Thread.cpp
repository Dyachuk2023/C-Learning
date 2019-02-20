#include <iostream>
#include <thread> //��� ����� �������
#include <mutex> //��� ������������� �������
#include <Windows.h>
using namespace std;


void Hello(mutex& mtx)
{
	while (1)
	{
		//mtx.lock(); - ��������� mutex � �������� ��������� �������� �� ������� mtx.unlock();
		mtx.lock();
		cout << "Hello Dmitry" << endl;

		//this_thread::get_id() - ���������� ���������� ����� ������
		cout << "Thread <Hello> id: " << this_thread::get_id() << endl;
		mtx.unlock();
		//������� ��������
		Sleep(700);
	}
}


void Bye(mutex& mtx)
{
	while (1)
	{
		//���� ������������� mutex, � ������ ����� mutex ����� �������������, ��������� ��� ��� ���� 
		mtx.lock();
		cout << "Bye Dmitry" << endl;
		cout << "Thread <Bye> id: " << this_thread::get_id() << endl;
		//������������� mutex ����� ���������� ���������� �������� 
		mtx.unlock();
		Sleep(700);
	}
}

int main(void)
{
	//thread::hardware_concurrency() - ������� ��� ����������� ���������� ������� � �������
	//cout << "Hardware concurrency: " << thread::hardware_concurrency() << endl;

	//cout << "Main id: " << this_thread::get_id() << endl;

	//mutex - ����� ����������� ��� �������������� ������������ �����
	mutex mtx;

	// � thread ��� ������������� �� �� ����� ���������� ���������� ���� �� ���� �� ������, �� ����� ���������� � ������� ref(����������)
	thread t1(Hello, ref(mtx));
	thread t2(Bye, ref(mtx));

	//.joinable() - �������� �� ����������� �������� ������
	if (t1.joinable()) 
		//�������� ������
		t1.join();

	if (t2.joinable())
		t2.join();
	//����� ������������ ������
	//t2.detach();
	system("pause");
}