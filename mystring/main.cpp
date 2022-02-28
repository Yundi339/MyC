#include <iostream>
#include "mystring.h"
using namespace std;

int main() 
{
	auto CreateTempString = []()->String {
		return String("temp");
	};
	auto CreateMoveString = []()->String {
		return std::move(String("move"));
	};
	/*
	String s1; //String()
	String s2 = String(); // String()

	String s3 = "s3"; // String(const char* str)
	String s4(String("s4")); // String(const char* str)

	String* s5 = new String(); // String()

	String* s6 = new String("s6"); // String(const char* str)
	String s7(*s6); // String(const String& s)

	delete s5; // ~String：String()
	delete s6; // ~String：String(const char* str)
	// 删除s6不会修改s7中的内容

	String s8 = String(String("s8")); // String(const char* str)
	String s9 = s8; // String(const String& s)

	String s10 = CreateTempString(); // String(const char* str)
	String s11 = CreateMoveString(); // String(const char* str) -> String(String &&other) -> ~String：String(const char* str)

	// s11: ~String：String(String &&other)
	// s10: ~String：String(const char* str)
	// s9: ~String：String(const String& s)
	// s8: ~String：String(const char* str)
	// s7 ~String：String(const String& s)
	// s4 ~String：String(const char* str)
	// s3 ~String：String(const char* str)
	// s2 ~String：String()
	// s1 ~String：String()
	*/

	/*
	String s12 = "s12"; // String(const char* str)
	String s13; // String()
	s13 = "s13"; // operator =(const char* str)
	// s13: ~String：String()
	// s14: ~String：String(const char* str)
	*/

	/*
	char* s16 = new char[4]{ "s16" };
	String s17 = s16; // String(const char* str)
	std::cout << "s16:" << (s16 != NULL) << "\ts17:" << s17 << std::endl; // s16:1   s17 : s16

	String s18; // String()
	s18 = s16; // operator =(const char* str)
	std::cout << "s16:" << (s16 != NULL) << "\ts18:" << s18 << std::endl; // s16 : 1   s18 : s16

	s18 = std::move(s16); // operator =(char* &&str)
	std::cout << "s16:" << (s16 != NULL) << "\ts18:" << s18 << std::endl; // s16 : 0   s18 : s16

	if (s16 != NULL) {
		std::cout << "s16 != NULL" << std::endl;
		delete[] s16;
	}
	// s18: ~String：String()
	// s17: ~String：String(const char* str)
	*/

	/*
	String s19; // String()
	s19 = CreateTempString(); // String(const char* str) -> operator =(String &&other) -> ~String：String(const char* str)
	String s20; // String()
	s20 = CreateTempString(); // String(const char* str) -> operator =(String && other) -> ~String：String(const char* str)
	// s20: ~String：String()
	// s19: ~String：String()
	*/

	/*
	String s21 = "s2" ; // String(const char* str)
	s21 += '1'; // operator +=(const char ch)
	std::cout << s21 << std::endl; // s21
	// ~String：String(const char* str)
	*/
	/*
	String s22 = "s"; // String(const char* str)
	s22 += "22"; // operator +=(const char* str)
	std::cout << s22 << std::endl; // s22
	// ~String：String(const char* str)
	*/

	/*
	String s23 = "s23"; // String(const char* str)
	String s24 = "s24"; // String(const char* str)
	s23 += s24; // operator +=(const String& other) -> operator +=(const char* str)
	std::cout << s23 << std::endl; // s23s24
	// s24 ~String：String(const char* str)
	// s23 ~String：String(const char* str)
	*/

	/*
	String s25 = "s25"; // String(const char* str)
	String s26 = s25 + '6';
	// operator +(const char ch) -> String(const String& s)
	// -> operator +=(const char ch) -> String(String &&other) -> ~String：String(const String& s)
	std::cout << s26 << std::endl; // s256

	String s27 = s25 + "s27";
	// operator +(const char* str) -> String(const String& s)
	// -> operator +=(const char* str) -> String(String&& other) -> ~String：String(const String & s)
	std::cout << s27 << std::endl; // s25s27

	String s28 = s26 + s27;
	// operator +(const String& other) -> String(const String& s)
	// -> operator +=(const String& other) -> operator +=(const char* str)
	// -> String(String&& other) -> ~String：String(const String & s)
	std::cout << s28 << std::endl; // s256s25s27

	String s29; // String()
	s29 = s26 + s27;
	// operator +(const String& other) -> String(const String& s)
	// -> operator +=(const String& other) -> operator +=(const char* str)
	// -> String(String&& other) -> ~String：String(const String & s)
	// -> operator =(const String & other) -> ~String：String(String && other)
	std::cout << s29 << std::endl; // s256s25s27
	//s29: ~String：String()
	//s28: ~String：String(String&& other)
	//s27: ~String：String(String&& other)
	//s26: ~String：String(String&& other)
	//s25: ~String：String(const char* str)
	*/

	/*
	String s30 = "s30";
	const char* s31 = s30.c_str();
	std::cout << s31[0] << s31[1] << s31[2] << std::endl; // s30
	std::cout << (s31[3] == '\0') << std::endl; // 1
	std::cout << s30[0] << s30[1] << s30[2] << std::endl; // s30
	std::cout << (s30[3] == '\0') << std::endl; // 程序中断
	*/

	return 0;
}