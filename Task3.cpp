#include <iostream>
#include <cstring>			// для использования size_t

using namespace std;

template<typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void push_back(T value);
	void pop_back();
	bool empty();
	size_t size();
	size_t capacity();

	T & operator[](const int index);
private:

	T *arr;		// хранит текущий массив
	T *last;	// указатель указывает на позицию следующую за последним элементом в массиве
	T *end;		// указатель "конца" выделенной памяти
};


template<typename T>
Vector<T>::Vector()
{
	last = end = arr = nullptr;
}


template<typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}


template<typename T>
void Vector<T>::push_back(T value)
{
	if (last == end)
	{
		int size = last - arr;
		int new_size = (size + 1) * 2;			// увеличиваем размер
		T *temp_arr = new T[new_size];

		for (int i = 0; i < size; i++)			// копируем все элементы из старого массива в новый
		{
			temp_arr[i] = arr[i];
		}

		delete[] this->arr;			
		
		arr = temp_arr;
		last = arr + size;		// ставим указатель last на прежнее положение в новом массиве
		end = arr + new_size;		// ставим указатель end
	}

	*last = value;		// записываем элемент в массив
	last++;			

}


template<typename T>
void Vector<T>::pop_back()
{
	if (last > arr)
		last--;
}

template<typename T>
bool Vector<T>::empty()
{
	return (arr == last);
}

template<typename T>
size_t Vector<T>::size()
{
	return size_t(last - arr);
}

template<typename T>
size_t Vector<T>::capacity()
{
	return size_t(end - arr);
}

template<typename T>
T & Vector<T>::operator[](const int index)
{
		return arr[index]; 
}



int main()
{
	ios::sync_with_stdio(false);

	int numb_of_elem;
	Vector<int> myVector;

	cout << "Hi!) How many values do I need to add?\n";	cin >> numb_of_elem;
	cout << "Enter all the elements: ";
	int value;
	for (int i = 0; i < numb_of_elem; i++)
	{
		cin >> value;
		myVector.push_back(value);
	}

	cout << "Your vector: ";
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << " ";
	}

	cout << "\nVector size: " << myVector.size();

	cout << "\nYour vector after pop_back(): ";
	myVector.pop_back();
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << " ";
	}

	cout << "\nVector size: " << myVector.size();

	cout << "\nMemory for vector is allocated: " << myVector.capacity();

	while (!myVector.empty())
		myVector.pop_back();
	cout << "\nVector is empty...\n";
	system("pause");
	return 0;
}

