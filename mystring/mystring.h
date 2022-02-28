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
	char* _str = NULL; // �����ַ���
	size_t _size = 0; // �ַ�������
	//std::string _log;
	static constexpr size_t _LIMIT_STRING_SIZE = 2048; // TODO: �����ַ�������ַ�����
	bool _SetString(const char* str); // д���ַ�����
	bool _MoveString(char* &str); // �ƶ��ַ�����
	bool _UnSafeMoveString(char*& str, size_t& size); // ����ȫ�ƶ��ַ�����
	bool _CompareLength(size_t& size); // �ж�Ŀ���С�Ƿ񳬳��ַ�������󳤶�
public:
	// Ĭ�Ϲ��캯��
	String();
	// ���� const char* �Ŀ������캯��
	String(const char* str);
	// ���� const String& �Ŀ������캯��
	String(const String& other);
	// ���� String&& �� move �������캯��
	String(String &&other) noexcept;
	// ��������
	virtual ~String();

	// ���� [] ������
	//char operator[](size_t index);
	char& operator[](size_t index);
	// �������������
	friend std::istream& operator >> (std::istream& cin, String& str);
	friend std::ostream& operator << (std::ostream& cout, String& str);
	//���������ַ
	String* GetAddress() { return this; }
	// ���ؿ�¡
	String GetCopy() { return *this; }
	// ���ر���
	String& GetOriginal() { return *this; }
	// �����ַ���������ַ������ַ,����const��ֹ���޸�
	const char* c_str() { return _str; }
	// �����ַ�������
	const size_t length() { return _size; }

	// ���� = ������
	String& operator =(const char* str);
	String& operator =(char* &&str);
	String& operator =(const String& other);
	String& operator =(String &&other) noexcept; // TODO: Unsafe

	// ���� + ������, ���ص�����ʱ���󣬲���Ҫʹ������
	const String operator +(const char ch);
	const String operator +(const char* str);
	const String operator +(const String& other);

	// ���� += ������
	String& operator +=(const char ch);
	String& operator +=(const char* str);
	String& operator +=(const String& other);

	// ���� == ������
	bool operator ==(const char* str);
	bool operator ==(const String& other);
};