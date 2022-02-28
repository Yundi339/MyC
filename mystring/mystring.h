#pragma once
#include <iostream>
#include <string.h>
#include <istream>
#include <ostream>
#include <iomanip>
//#include <stdexcept>
//#include <cassert> 


class String {
private:
	char* _str = NULL; // 储存字符串
	size_t _size = 0; // 字符串长度
	//std::string _log;
	static constexpr size_t _LIMIT_STRING_SIZE = 2048; // TODO: 限制字符串最大字符长度
	bool _SetString(const char* str); // 写入字符数组
	bool _MoveString(char* &str); // 移动字符数组
	bool _UnSafeMoveString(char*& str, size_t& size); // 不安全移动字符数组
	bool _CompareLength(size_t& size); // 判断目标大小是否超出字符串的最大长度
public:
	// 默认构造函数
	String();
	// 传入 const char* 的拷贝构造函数
	String(const char* str);
	// 传入 const String& 的拷贝构造函数
	String(const String& other);
	// 传入 String&& 的 move 拷贝构造函数
	String(String &&other) noexcept;
	// 析构函数
	virtual ~String();

	// 重载 [] 操作符
	//char operator[](size_t index);
	char& operator[](size_t index);
	// 重载输入输出流
	friend std::istream& operator >> (std::istream& cin, String& str);
	friend std::ostream& operator << (std::ostream& cout, String& str);
	//返回自身地址
	String* GetAddress() { return this; }
	// 返回克隆
	String GetCopy() { return *this; }
	// 返回本身
	String& GetOriginal() { return *this; }
	// 返回字符串本身的字符数组地址,加上const防止被修改
	const char* c_str() { return _str; }
	// 返回字符串长度
	const size_t length() { return _size; }

	// 重载 = 操作符
	String& operator =(const char* str);
	String& operator =(char* &&str);
	String& operator =(const String& other);
	String& operator =(String &&other) noexcept; // TODO: Unsafe

	// 重载 + 操作符, 返回的是临时对象，不需要使用引用
	const String operator +(const char ch);
	const String operator +(const char* str);
	const String operator +(const String& other);

	// 重载 += 操作符
	String& operator +=(const char ch);
	String& operator +=(const char* str);
	String& operator +=(const String& other);

	// 重载 == 操作符
	bool operator ==(const char* str);
	bool operator ==(const String& other);
};