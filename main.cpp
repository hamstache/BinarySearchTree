#include "BSTNode.h"
#include "BSTSimple.h"

#include <iostream>
#include <string>
using namespace std;

int main(){
	BSTSimple<char, int> cList;
	cList.put('M', 1);
	cList.put('G', 2);
	cList.put('C', 4);
	cList.put('I', 5);
	cList.put('R', 3);
	cList.put('O', 6);
	cList.put('S', 7);
    
	BSTSimple<string, int> strList;
	strList.put("this", 1);
	strList.put("is", 2);
	strList.put("fresh", 3);
	strList.put("lacquer", 4);
    
	strList.put("seriously", 5);
	strList.put("were", 6);
	strList.put("you", 7);
	strList.put("raised", 8);
	strList.put("in", 9);
	strList.put("a", 10);
	strList.put("barn", 11);
    
	BSTSimple<int, string> iList;
	iList.put(50, "fifty");
	iList.put(25, "twenty-five");
	iList.put(75, "seventy-five");
	iList.put(12, "twelve");
	iList.put(37, "thirty-seven");
	iList.put(62, "sixty-two");
	iList.put(85, "eighty-five");
    
	cout << "...Preorder: \n"; cList.print(std::cout, BSTNode<char, int>::TRAVERSAL::PREORDER); cout << endl;
	cout << "...Inorder: \n"; cList.print(std::cout, BSTNode<char, int> ::TRAVERSAL::INORDER); cout << endl;
	cout << "...Postorder: \n"; cList.print(std::cout, BSTNode<char, int>::TRAVERSAL::POSTORDER); cout << endl;
    
	cout << "...Preorder: \n"; strList.print(std::cout, BSTNode<string, int> ::TRAVERSAL::PREORDER); cout << endl;
	cout << "...Inorder: \n"; strList.print(std::cout, BSTNode<string, int>::TRAVERSAL::INORDER); cout << endl;
	cout << "...Postorder: \n"; strList.print(std::cout, BSTNode<string, int> ::TRAVERSAL::POSTORDER); cout << endl;
    
	cout << "...Preorder: \n"; iList.print(std::cout, BSTNode<int, string>::TRAVERSAL::PREORDER); cout << endl;
	cout << "...Inorder: \n"; iList.print(std::cout, BSTNode<int, string> ::TRAVERSAL::INORDER); cout << endl;
	cout << "...Postorder: \n"; iList.print(std::cout, BSTNode<int, string>::TRAVERSAL::POSTORDER); cout << endl;
    
	cin.get();
	return 0;
}


