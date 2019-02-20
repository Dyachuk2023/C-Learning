#include <iostream>
#include <thread> //для самих потоков
#include <mutex> //для синхронизации потоков
#include <Windows.h>
using namespace std;


void Hello(mutex& mtx)
{
	while (1)
	{
		//mtx.lock(); - блокирует mutex и начинает выполнать операции до встречи mtx.unlock();
		mtx.lock();
		cout << "Hello Dmitry" << endl;

		//this_thread::get_id() - возвращает уникальный номер потока
		cout << "Thread <Hello> id: " << this_thread::get_id() << endl;
		mtx.unlock();
		//функция ожидания
		Sleep(700);
	}
}


void Bye(mutex& mtx)
{
	while (1)
	{
		//ждет разблокировки mutex, и только когда mutex будет разблокирован, блокирует его под себя 
		mtx.lock();
		cout << "Bye Dmitry" << endl;
		cout << "Thread <Bye> id: " << this_thread::get_id() << endl;
		//разблокировка mutex после выполнения конкретной операции 
		mtx.unlock();
		Sleep(700);
	}
}

int main(void)
{
	//thread::hardware_concurrency() - функция для определения количества потоков в системе
	//cout << "Hardware concurrency: " << thread::hardware_concurrency() << endl;

	//cout << "Main id: " << this_thread::get_id() << endl;

	//mutex - будет блокировать или разблокировать определенный поток
	mutex mtx;

	// в thread при инициализации мы не можем передавать переменные сами по себе по ссылке, их нужно передавать в обертке ref(переменная)
	thread t1(Hello, ref(mtx));
	thread t2(Bye, ref(mtx));

	//.joinable() - проверка на возможность привязки потока
	if (t1.joinable()) 
		//привязка потока
		t1.join();

	if (t2.joinable())
		t2.join();
	//метод отсоиденения потока
	//t2.detach();
	system("pause");
}