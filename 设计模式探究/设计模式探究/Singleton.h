#pragma once

//template<typename T>
//class Singleton {
//private:
//	static T _eton;
//private:
//	Singleton() {}//˽�л����캯��
//	~Singleton() {}
//public:
//	Singleton(const Singleton&) = delete;//ɾ����������
//	Singleton& operator=(const Singleton&) = delete;//ɾ����ֵ��������
//	static T& getInstance()
//	{
//		return _eton;
//	}
//};
//
//template<typename T>
//T Singleton<T>::_eton = T();

 //����ģʽ
template <typename T>
class Singleton {
private:
	Singleton() {}
	~Singleton() {}
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static T& getInstance()
	{
		static T _eton=T();
		return _eton;
	}
};