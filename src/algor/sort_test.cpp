#include "gtest/gtest.h"
#include "Sort.cpp"
#include <string>
#include <math.h>

using namespace std;
using namespace testing;

template<class T>
struct spara
{
	spara(T _begin=NULL, T _end =NULL) :begin(_begin), end(_end) {}
	~spara()
	{
		//cout << "enter " << __FUNCTION__ << endl;
		delete []begin;
		//cout << "leave " << __FUNCTION__ << endl;
	}
	T begin;
	T end;
};



class SortTest :public testing::Test {
public:
	int * randomArray(int *n)
	{
		srand(++seed);
		*n = rand() % 10 + 10;
		int *a = new int[*n];
		for (int i = 0; i < *n; ++i)
		{
			a[i] = rand() % 30;
		}
		return a;
	}
	virtual void SetUp()
	{
	//	cout << "enter " << __FUNCTION__ << endl;
		int n = 0;
		int *a = randomArray(&n);
		share = new spara<int *>(a, a + n);
	}

	virtual void TearDown()
	{
		//cout << "enter " << __FUNCTION__ << endl;
		delete share;
	}
	
	~SortTest()
	{
		
	}
	spara< int *>  *share;
	static unsigned int seed;
};

unsigned int SortTest::seed = 0;

template<class Iterator>
void test_sort(string sort_name, Iterator begin, Iterator end)
{
	int n = end - begin;
	cout << "sort type " << sort_name << endl;
	for (Iterator it = begin; it != end; ++it)
		cout << *it << " ";
	cout << endl;
	if (sort_name == "bubble")
		bubble_sort(begin, end);
	else if (sort_name == "quick")
		quick_sort(begin, end);
	else if (sort_name == "merge")
		merge_sort(begin, end);
	else if (sort_name == "insert")
		insert_sort(begin, end);
	for (Iterator it = begin; it != end-1; ++it)
	{
		EXPECT_LE(*it, *(it + 1));
	}
}

TEST_F(SortTest, bubblesort)
{
	test_sort("bubble", share->begin, share->end);
}

TEST_F(SortTest, buublesort)
{
	test_sort("bubble", share->begin, share->end);
}

TEST_F(SortTest, quick)
{
	test_sort("quick", share->begin, share->end);
}

class A
{
public:
	int *a;
	A()
	{
		a = new int();
	}
};

int main(int argc, char **argv)
{
	InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}