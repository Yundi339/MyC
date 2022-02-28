#include "mystring.h"



// 判断目标大小是否超出字符串的最大长度
const bool String::_CompareLength(size_t& size)
{
	return size + 1 > String::_LIMIT_STRING_SIZE;
}


// 写入字符数组
// String._str <- char* str
inline bool String::_SetString(const char* str)
{
	// 传入空指针
	if (str == NULL) {
		_size = 0;
		_str = NULL;
		return false;
	}
	else {
		size_t size = strlen(str);
		// 超出字符串最大限制长度
		if (_CompareLength(size)) {
			throw std::bad_alloc();
			return false;
		}
		// 释放原空间
		if (_str != NULL) {
			delete[] _str;
			_str = NULL;
		}
		// 拷贝字符数组
		_size = size;
		_str = new char[_size + 1];
		strcpy(_str, str);
		_str[_size] = '\0';
	}
	return true;
}

// 移动字符数组
// String._str <- move(char*& str)
inline bool String::_MoveString(char* &str)
{
	// 传入空指针
	if (str == NULL) {
		_size = 0;
		_str = NULL;
		return false;
	}
	else {
		size_t size = strlen(str);
		// 超出字符串最大限制长度
		if (_CompareLength(size)) {
			throw std::bad_alloc();
			return false;
		}
		// 释放原空间
		if (_str != NULL) {
			delete[] _str;
			_str = NULL;
		}
		// 移动地址
		_size = size;
		_str = str;  // TODO: _str = std::move(str);
		_str[_size] = '\0'; // TODO: 可能上面的strlen就炸了
		str = NULL; // 将原字符数组的地址变为NULL
	}
	return true;
}

// 不安全移动字符数组
// (String._str, String._size) <- move(char*& str, size_t&)
inline bool String::_UnSafeMoveString(char* &str, size_t& size)
{
	// 释放原空间
	if (_str != NULL) {
		delete[] _str;
		_str = NULL;
	}
	// 移动地址
	_str = str;
	_size = size;
	str = NULL; // 将原字符数组的地址变为NULL
	size = 0; // 将原长度变为0
	return true;
}



// 默认构造函数
String::String() {
	//_log = "String()";
	//std::cout << _log << std::endl;

}

// 传入 const char* 的拷贝构造函数
String::String(const char* str)
{
	//_log = "String(const char* str)";
	//std::cout << _log << std::endl;

	_SetString(str);
}

// 传入 const String& 的拷贝构造函数
String::String(const String& other)
{
	//_log = "String(const String& s)";
	//std::cout << _log << std::endl;
	_SetString(other._str);
}

// 传入 String&& 的 move 拷贝构造函数
String::String(String &&other) noexcept
{
	//_log = "String(String &&other)";
	//std::cout << _log << std::endl;
	_MoveString(other._str);
	// 下面的代码等价于 _MoveString(other._str);
	//if (_str != NULL) {
	//	delete[] _str;
	//	_str = NULL;
	//}
	//_size = other._size;
	//_str = other._str;
	//other._size = 0;
	//other._str = NULL;

	//std::cout << (other._str == NULL);
}

// 析构函数
String::~String()
{
	//std::cout << "~String：" << _log << std::endl;
	if (_str != NULL) {
		//std::cout << _str << std::endl;
		delete[] _str;
		_str = NULL;
	}
}

// 重载 [] 操作符
// (char)Elem1 = (String) Elem2[index]
// (String)Elem1[index] = (char) Elem2
char& String::operator [](size_t index)
{
	//std::cout << "index" << index << std::endl;
	if (index >= _size)	{
		throw;
	}
	return _str[index];
}

// 重载输入流
// cin >> (String) Elem
std::istream& operator >>(std::istream& cin, String& str)
{
	// new一个字符数组，将字符数组move到String中
	char* t_str = new char[String::_LIMIT_STRING_SIZE];
	cin >> std::setw(String::_LIMIT_STRING_SIZE) >> t_str;
	str._MoveString(t_str);
	//if (t_str == NULL)std::cout << "NULL"; // 检测move函数是否实现
	return cin;
}

// 重载输出流
// cout << (String) Elem
std::ostream& operator <<(std::ostream& cout, String& str)
{
	// 检查字符数组非NULL指针
	if (str.c_str() != NULL) {
		cout << str.c_str();
	}
	return cout;
}

// 重载 = 操作符，直接拷贝字符数组
String& String::operator =(const char* str)
{
	//std::cout << "operator =(const char* str)" << std::endl;
	// 检查自赋点
	if (_str != str) {
		// 写入字符数组
		_SetString(str);
	}
	return *this;
}

// 重载 = 操作符，move字符数组
String& String::operator =(char* &&str)
{
	//std::cout << "operator =(char* &&str)" << std::endl;
	// 检查自赋点
	if (_str != str) {
		// move字符数组
		_MoveString(str);
	}
	return *this;
}

// 重载 = 操作符，直接拷贝类中的字符数组
String& String::operator =(const String& other)
{
	//std::cout << "operator =(const String& other)" << std::endl;
	// 检查自赋点
	if (this != &other) {
		// 写入字符数组
		_SetString(other._str);
	}
	return *this;
}

// 重载 = 操作符，传入 String&& 的 move 赋值函数
String& String::operator =(String &&other) noexcept
{
	//std::cout << "operator =(String &&other)" << std::endl;
	// 检查自赋点
	if (this != &other) {
		_MoveString(other._str);
	}
	return *this;
}

// 重载 += 操作符
// (String) Elem1 += (char) Elem2
String& String::operator +=(const char ch)
{
	//std::cout << "operator +=(const char ch)" << std::endl;
	if (_str == NULL) {
		throw std::runtime_error("Null Pointer");
	}
	size_t t_size = _size + 1;
	// 超出字符串最大限制长度
	if (_CompareLength(t_size)) {
		throw std::bad_alloc();
	}
	char* t_str = new char[t_size + 1];
	strcpy(t_str, _str);  // 拷贝原字符数组
	t_str[t_size - 1] = ch; // 拷贝新字符
	t_str[t_size] = '\0';
	_UnSafeMoveString(t_str, t_size);
	return *this;
}

// 重载 += 操作符
// (String) Elem1 += (char[]) Elem2
String& String::operator +=(const char* str)
{
	//std::cout << "operator +=(const char* str)" << std::endl;
	if (_str == NULL) {
		throw std::runtime_error("Null Pointer");
	}
	if (str == NULL) {
		throw std::runtime_error("Null Pointer");
	}
	size_t t_size = strlen(str) + _size;
	// 超出字符串最大限制长度
	if (_CompareLength(t_size)) {
		throw std::bad_alloc();
	}
	char* t_str = new char[t_size + 1];
	// 拷贝旧新字符数组
	strcpy(t_str, _str); // 拷贝原字符数组
	strcpy(t_str + _size, str); // 拷贝新字符数组
	t_str[t_size] = '\0';
	_UnSafeMoveString(t_str, t_size);
	return *this;
}

// 重载 += 操作符
// (String) Elem1 += (String) Elem2
String& String::operator +=(const String& other)
{
	//std::cout << "operator +=(const String& other)" << std::endl;
	if (_str == NULL) {
		throw std::runtime_error("Null Pointer");
	}
	if (other._str == NULL) {
		throw std::runtime_error("Null Pointer");
	}
	*this += other._str;
	return *this;
}

// 重载 + 操作符
// (String) Elem1 + (char) Elem2
const String String::operator +(const char ch)
{
	//std::cout << "operator +(const char ch)" << std::endl;
	String _temp(*this);
	_temp += ch;
	return std::move(_temp);
}

// 重载 + 操作符
// (String) Elem1 + (char*) Elem2
const String String::operator +(const char* str)
{
	//std::cout << "operator +(const char* str)" << std::endl;
	String _temp(*this);
	_temp += str;
	return std::move(_temp);
}


// 重载 + 操作符
// (String) Elem1 + (String) Elem2
const String String::operator +(const String& other)
{
	//std::cout << "operator +(const String& other)" << std::endl;
	String _temp(*this);
	_temp += other;
	// return _temp; // 会触发拷贝构造
	return std::move(_temp);

}


// 重载 == 操作符
// (String) Elem1 == (char[]) Elem2
const bool String::operator ==(const char* str)
{
	if (_str == NULL || str == NULL){
		return false;
	}
	if (_str == str) {
		return true;
	}
	if (_size != strlen(str))
		return false;
	return (strcmp(_str, str) == 0);
}

// 重载 == 操作符
// (String) Elem1 == (String) Elem2
const bool String::operator ==(const String& other)
{
	if (*this == other) {
		return true;
	}
	return (_str == other._str);
}


