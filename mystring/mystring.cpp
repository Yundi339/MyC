#include "mystring.h"



// �ж�Ŀ���С�Ƿ񳬳��ַ�������󳤶�
const bool String::_CompareLength(size_t& size)
{
	return size + 1 > String::_LIMIT_STRING_SIZE;
}


// д���ַ�����
// String._str <- char* str
inline bool String::_SetString(const char* str)
{
	// �����ָ��
	if (str == NULL) {
		_size = 0;
		_str = NULL;
		return false;
	}
	else {
		size_t size = strlen(str);
		// �����ַ���������Ƴ���
		if (_CompareLength(size)) {
			throw std::bad_alloc();
			return false;
		}
		// �ͷ�ԭ�ռ�
		if (_str != NULL) {
			delete[] _str;
			_str = NULL;
		}
		// �����ַ�����
		_size = size;
		_str = new char[_size + 1];
		strcpy(_str, str);
		_str[_size] = '\0';
	}
	return true;
}

// �ƶ��ַ�����
// String._str <- move(char*& str)
inline bool String::_MoveString(char* &str)
{
	// �����ָ��
	if (str == NULL) {
		_size = 0;
		_str = NULL;
		return false;
	}
	else {
		size_t size = strlen(str);
		// �����ַ���������Ƴ���
		if (_CompareLength(size)) {
			throw std::bad_alloc();
			return false;
		}
		// �ͷ�ԭ�ռ�
		if (_str != NULL) {
			delete[] _str;
			_str = NULL;
		}
		// �ƶ���ַ
		_size = size;
		_str = str;  // TODO: _str = std::move(str);
		_str[_size] = '\0'; // TODO: ���������strlen��ը��
		str = NULL; // ��ԭ�ַ�����ĵ�ַ��ΪNULL
	}
	return true;
}

// ����ȫ�ƶ��ַ�����
// (String._str, String._size) <- move(char*& str, size_t&)
inline bool String::_UnSafeMoveString(char* &str, size_t& size)
{
	// �ͷ�ԭ�ռ�
	if (_str != NULL) {
		delete[] _str;
		_str = NULL;
	}
	// �ƶ���ַ
	_str = str;
	_size = size;
	str = NULL; // ��ԭ�ַ�����ĵ�ַ��ΪNULL
	size = 0; // ��ԭ���ȱ�Ϊ0
	return true;
}



// Ĭ�Ϲ��캯��
String::String() {
	//_log = "String()";
	//std::cout << _log << std::endl;

}

// ���� const char* �Ŀ������캯��
String::String(const char* str)
{
	//_log = "String(const char* str)";
	//std::cout << _log << std::endl;

	_SetString(str);
}

// ���� const String& �Ŀ������캯��
String::String(const String& other)
{
	//_log = "String(const String& s)";
	//std::cout << _log << std::endl;
	_SetString(other._str);
}

// ���� String&& �� move �������캯��
String::String(String &&other) noexcept
{
	//_log = "String(String &&other)";
	//std::cout << _log << std::endl;
	_MoveString(other._str);
	// ����Ĵ���ȼ��� _MoveString(other._str);
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

// ��������
String::~String()
{
	//std::cout << "~String��" << _log << std::endl;
	if (_str != NULL) {
		//std::cout << _str << std::endl;
		delete[] _str;
		_str = NULL;
	}
}

// ���� [] ������
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

// ����������
// cin >> (String) Elem
std::istream& operator >>(std::istream& cin, String& str)
{
	// newһ���ַ����飬���ַ�����move��String��
	char* t_str = new char[String::_LIMIT_STRING_SIZE];
	cin >> std::setw(String::_LIMIT_STRING_SIZE) >> t_str;
	str._MoveString(t_str);
	//if (t_str == NULL)std::cout << "NULL"; // ���move�����Ƿ�ʵ��
	return cin;
}

// ���������
// cout << (String) Elem
std::ostream& operator <<(std::ostream& cout, String& str)
{
	// ����ַ������NULLָ��
	if (str.c_str() != NULL) {
		cout << str.c_str();
	}
	return cout;
}

// ���� = ��������ֱ�ӿ����ַ�����
String& String::operator =(const char* str)
{
	//std::cout << "operator =(const char* str)" << std::endl;
	// ����Ը���
	if (_str != str) {
		// д���ַ�����
		_SetString(str);
	}
	return *this;
}

// ���� = ��������move�ַ�����
String& String::operator =(char* &&str)
{
	//std::cout << "operator =(char* &&str)" << std::endl;
	// ����Ը���
	if (_str != str) {
		// move�ַ�����
		_MoveString(str);
	}
	return *this;
}

// ���� = ��������ֱ�ӿ������е��ַ�����
String& String::operator =(const String& other)
{
	//std::cout << "operator =(const String& other)" << std::endl;
	// ����Ը���
	if (this != &other) {
		// д���ַ�����
		_SetString(other._str);
	}
	return *this;
}

// ���� = ������������ String&& �� move ��ֵ����
String& String::operator =(String &&other) noexcept
{
	//std::cout << "operator =(String &&other)" << std::endl;
	// ����Ը���
	if (this != &other) {
		_MoveString(other._str);
	}
	return *this;
}

// ���� += ������
// (String) Elem1 += (char) Elem2
String& String::operator +=(const char ch)
{
	//std::cout << "operator +=(const char ch)" << std::endl;
	if (_str == NULL) {
		throw std::runtime_error("Null Pointer");
	}
	size_t t_size = _size + 1;
	// �����ַ���������Ƴ���
	if (_CompareLength(t_size)) {
		throw std::bad_alloc();
	}
	char* t_str = new char[t_size + 1];
	strcpy(t_str, _str);  // ����ԭ�ַ�����
	t_str[t_size - 1] = ch; // �������ַ�
	t_str[t_size] = '\0';
	_UnSafeMoveString(t_str, t_size);
	return *this;
}

// ���� += ������
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
	// �����ַ���������Ƴ���
	if (_CompareLength(t_size)) {
		throw std::bad_alloc();
	}
	char* t_str = new char[t_size + 1];
	// ���������ַ�����
	strcpy(t_str, _str); // ����ԭ�ַ�����
	strcpy(t_str + _size, str); // �������ַ�����
	t_str[t_size] = '\0';
	_UnSafeMoveString(t_str, t_size);
	return *this;
}

// ���� += ������
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

// ���� + ������
// (String) Elem1 + (char) Elem2
const String String::operator +(const char ch)
{
	//std::cout << "operator +(const char ch)" << std::endl;
	String _temp(*this);
	_temp += ch;
	return std::move(_temp);
}

// ���� + ������
// (String) Elem1 + (char*) Elem2
const String String::operator +(const char* str)
{
	//std::cout << "operator +(const char* str)" << std::endl;
	String _temp(*this);
	_temp += str;
	return std::move(_temp);
}


// ���� + ������
// (String) Elem1 + (String) Elem2
const String String::operator +(const String& other)
{
	//std::cout << "operator +(const String& other)" << std::endl;
	String _temp(*this);
	_temp += other;
	// return _temp; // �ᴥ����������
	return std::move(_temp);

}


// ���� == ������
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

// ���� == ������
// (String) Elem1 == (String) Elem2
const bool String::operator ==(const String& other)
{
	if (*this == other) {
		return true;
	}
	return (_str == other._str);
}


